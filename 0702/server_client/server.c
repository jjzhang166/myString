/*************************************************************************
	> File Name: server.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月02日 星期三 22时39分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#define IP "192.168.1.71"
#define PORT 8888
int main(int argc,char* argv[])
{
	int fd_server;
	int fd_client;
	fd_server=socket(AF_INET,SOCK_STREAM,0);
	if(fd_server==-1)
	{
		perror("open error");
		exit(-1);
	}
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s

}
