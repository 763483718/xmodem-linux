/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-13 15:13:05
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-15 00:48:23
 */
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "xmodem.hpp"
using namespace std;

int main(int argc, char **argv) 
{
    // unsigned char p[] = {0x01,0x02};
    // int temp = *p;
    // cout << *p << endl;
    // return 0;

    int a;
    cout << "1:Send\t2:Receive\n";
    cin >> a;
    if(a == 1)
    {
        open_port(argv[1]);
        


        ifstream is("./CMakeCache.txt",ifstream::in | ios::binary);
        is.seekg(0, is.end);
        int length = is.tellg();
        cout << length << endl;
        is.seekg(0, is.beg);

        char* buffer = new char[length];
        is.read(buffer, length);

length = 13;
        while(1)
        {
            unsigned char temp = (length) & 0xff;
            lowLevel_write(&temp, 1);
            usleep(500);
        }


        unsigned char *fileSize = new unsigned char[4];
        for(int i = 0; i < 4;++i)
        {
            fileSize[i] = (length >> (8 * i)) & 0xff;
        }
        port_outStream(fileSize, 4);
        unsigned char ret;
        lowLevel_read(&ret, 1, 100000);
        if(ret != 0x01)
        {
            std::cout << "send file size error\n";
            return -1;
        }


        xmodemTransmit((unsigned char*)buffer, length);
        
        delete buffer;

        // unsigned char* buf = new unsigned char[164050];
        // for(int i = 0;i < 164050; ++i)
        // {
        //     buf[i] = buffer[i];
        // }
        // ofstream fout("./3.png", ios::binary);
        // fout.write((char*)buf, 164050);
        // fout.close();
        // delete buffer;
        // delete buf;


        // unsigned char* buf = (unsigned char*)"123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
        // cout << "sizeof:\t" << sizeof(buf) << endl;
        // xmodemTransmit(buf, 600);
    }
    else
    {

        open_port(argv[1]);

        int length = 0;
        unsigned char* fileSize = new unsigned char[4];
        lowLevel_read(fileSize, 4, 100000);
        // unsigned char fileSize [4] = {243,1,0,0};
        for(int i = 0; i < 4;++i)
        {
            unsigned int temp = fileSize[i];
            length += (temp << (8 * i));
            cout << "temp:\t" << (int)temp << endl;
        }
        std::cout << "length:\t" << length << std::endl;
        unsigned char ret = 0x01;
        lowLevel_write(&ret, 1);

        unsigned char* buf = new unsigned char[length];
        xmodemReceive(buf, length);

        ofstream fout("./CMakeLists.txt", ios::binary);
        if(!fout)
        {
            cout << "error in open\n";
        }else
        {
            fout.write((char*)buf, length);
            fout.close();
        }
        delete buf;
        
    }
    


    return 0;
}