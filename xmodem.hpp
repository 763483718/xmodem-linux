/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-13 15:13:44
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-14 22:42:09
 */

#ifndef XMODEM
#define XMODEM

#include "crc16.hpp"

#include <string.h>

#define SOH  0x01
#define STX  0x02
#define SOK  0x03
#define EOT  0x04
#define ACK  0x06
#define NAK  0x15
#define CAN  0x18
#define CTRLZ 0x1A

#define DLY_1S 1000
#define MAXRETRANS 25

#include "xmodem_linux.hpp"

//需要根据运行平台，实现的函数
int open_port(char * ttyName);
int lowLevel_write(unsigned char *buf, int size);
int lowLevel_read(unsigned char *buf, int size, int time_out);

int xmodemReceive(unsigned char *dest, int destsz);
int xmodemTransmit(unsigned char *src, int srcsz);


void port_outStream(unsigned char* stream, int size);

int port_inStream(unsigned char* stream,int size, int time_out);

static unsigned char* test_buf;

#endif