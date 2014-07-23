/*************************************************************************
	> File Name: hton.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月02日 星期三 09时42分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define HTON(ip) ((ip&(unsigned int)0xff)<<24)|((ip&((unsigned int)0x00ff<<8))<<8)|((ip&((unsigned int)0x00ff<<16))>>8)|((ip&((unsigned int)0x00ff<<24))>>24)
int main()
{
	//将小端转化为大端
	int a[4];
	char ip[64];
	int my_host;
	int my_net;
	scanf("%s",ip);//192.168.1.100
	sscanf(ip,"%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
	my_host=(a[0]<<24)|(a[1]<<16)|(a[2]<<8)|(a[3]);
	printf("my_host:%x\n",my_host);
	my_net=HTON(my_host);
	printf("network:%x\n",my_net);
	return 0;
}
