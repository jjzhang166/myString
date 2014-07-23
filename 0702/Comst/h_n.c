/*************************************************************************
	> File Name: h_n.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月08日 星期二 16时45分23秒
 ************************************************************************/

#include<stdio.h>
//host to network
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
int main(int argc,char* argv[])
{
	struct in_addr my_net;
	inet_aton(argv[1],&my_net);
	printf("inet_aton:%x\n",my_net.s_addr);
	memset(&my_net,0,sizeof(my_net));
	my_net.s_addr=inet_addr(argv[1]);//ip address can be 32bit
	printf("inet_addr:%x\n",inet_addr(argv[1]));
	printf("inet_ntoa:%s\n",inet_ntoa(my_net));
	return 0;
}
