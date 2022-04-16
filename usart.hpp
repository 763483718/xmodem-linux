/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-12 22:06:52
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-12 22:12:10
 */
#ifndef  _USART_H
#define  _USART_H

//������ص�ͷ�ļ�    
#include<stdio.h>      /*��׼�����������*/    
#include<stdlib.h>     /*��׼�����ⶨ��*/    
#include<unistd.h>     /*Unix ��׼��������*/    
#include<sys/types.h>     
#include<sys/stat.h>       
#include<fcntl.h>      /*�ļ����ƶ���*/    
#include<termios.h>    /*PPSIX �ն˿��ƶ���*/    
#include<errno.h>      /*����Ŷ���*/    
#include<string.h>    
     
     
//�궨��    
#define FALSE  -1    
#define TRUE   0
int UART0_Open(int fd,char*port);
void UART0_Close(int fd) ; 
int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity);
int UART0_Init(int fd, int speed,int flow_ctrl,int databits,int stopbits,int parity) ;
int UART0_Recv(int fd, char *rcv_buf,int data_len);
int UART0_Send(int fd, unsigned char *send_buf,int data_len);

#endif



