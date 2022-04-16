/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-12 20:01:56
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-13 18:04:18
 */

#ifndef XMODEM_LINUX
#define XMODEM_LINUX

#include <pthread.h> 
#include <mutex>
#include <condition_variable>
// #include <chrono>

//串口相关的头文件    
#include<stdio.h>      /*标准输入输出定义*/    
#include<stdlib.h>     /*标准函数库定义*/    
#include<unistd.h>     /*Unix 标准函数定义*/    
#include<sys/types.h>     
#include<sys/stat.h>       
#include<fcntl.h>      /*文件控制定义*/    
#include<termios.h>    /*PPSIX 终端控制定义*/    
#include<errno.h>      /*错误号定义*/    
#include<string.h> 

#include "usart.hpp"

#include <iostream>

using std::mutex;


int open_port(char * ttyName);
int lowLevel_write(unsigned char *buf, int size);
int lowLevel_read(unsigned char *buf, int size, int timeout = 1000);
int close_port();

void* read_thread_func(void*);

#endif