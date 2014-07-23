/*************************************************************************
	> File Name: my_inet_ntoa.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月02日 星期三 13时32分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*
	struct sockaddr_in recv={0};
	struct scokaddr_in sa={0};
	recv.sin_addr.s_addr=-217732928;//192.168.5.243
	sa.sin_addr.s_addr=--939415360;//192.168.5.200
*/

	int ip=0xc0a80164;//初始化
	int a[4],i;
	char b[20],c[15],d[10],e[5];
	a[0]=(ip&0xff000000)>>24;
	a[1]=(ip&0x00ff0000)>>16;
	a[2]
	printf("%d\n",a[0]);
	return 0;
}
