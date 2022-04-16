/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-12 20:02:04
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-15 00:33:28
 */
#include "xmodem_linux.hpp"


int fd;
unsigned char *buffer;
unsigned int bufferSize = 1024 * 3;
unsigned int bufferLen = 0;
unsigned int targetSize;
pthread_t read_thread;

bool shutdown;
mutex mutex_shutdown;

std::condition_variable cond_buf;
mutex mutex_buf;


int open_port(char * ttyName)
{
    fd = open(ttyName,O_RDWR | O_NOCTTY | O_NONBLOCK);

    if(fd==-1)
    {
        perror("Can't Open SerialPort");
        return -1;
    }else
    {
        printf("succ!\n");
    }
    buffer = new unsigned char[bufferSize];
    pthread_create(&read_thread, NULL, read_thread_func, NULL);
    return 0;
}

int close_port()
{
    std::lock_guard<std::mutex> guard(mutex_shutdown);
    shutdown = true;
    UART0_Close(fd);
    delete buffer;
}


int lowLevel_write(unsigned char *buf, int size)
{
    int len = UART0_Send(fd, buf, size);
    // std::cout << "write:\t" << *buf << "\tsize:\t"<< size << std::endl;
    std::cout << "size:\t"<< size << std::endl;

    // for(int i = 0;i < size; ++i)
    // {
    //     std::cout << (int)(*(buf + i)) << "  ";
    // }
    // std::cout << std::endl;
    // usleep(10);
    return 0;
}

int lowLevel_read(unsigned char *buf, int size, int timeout)
{
    std::unique_lock<std::mutex> lck(mutex_buf);
    targetSize = size;
    if(bufferLen < size)
    {
        std::chrono::milliseconds m1(timeout);//毫秒
        if(!cond_buf.wait_for(lck, m1, []{return bufferLen >= targetSize;}))
        {
            //失败
            lck.unlock();
            return -1;
        }
    }
    // std::cout << bufferLen << ":\t";
    // for(int i = 0; i < size;++i)
    // {
    //     std::cout << *(buffer + i);
    // }
    // std::cout << std::endl;
    //读到
    memcpy(buf, buffer, size);
    unsigned char *temp = new unsigned char[bufferSize];
    memcpy(temp, &buffer[size], bufferLen - size);
    bufferLen -= size;
    memcpy(buffer, temp, bufferLen);

    delete temp;
    lck.unlock();
    return size;
}

void* read_thread_func(void*)
{
    printf("thread open succ\n");
    char rcv_buf[1024];
    int index = 0;
    while(1)
    {
        ++index;
        // std::cout << "while" << index << std::endl;
        
        std::lock_guard<std::mutex> guard(mutex_shutdown);
        if(shutdown)
        {
            break;
        }
        int len = UART0_Recv(fd, rcv_buf,sizeof(rcv_buf));
        if(len > 0)
        {
            // std::cout << "read len:\t" << len << std::endl;
            if(bufferLen + len > bufferSize)
            {
                len = bufferSize - bufferLen;
            }
            std::lock_guard<std::mutex> guard(mutex_buf);
            memcpy(buffer+bufferLen, rcv_buf, len);
            bufferLen += len;

            // rcv_buf[len] = '\0';
            // std::cout << "rcv:\t" << rcv_buf << std::endl;
        }
        cond_buf.notify_one();
        usleep(500);
    }
    pthread_exit(NULL);
}