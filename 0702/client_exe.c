/*************************************************************************
	> File Name: client_exe.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月03日 星期四 01时14分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/tpyes.h>
#include<netinet/in.h>
#include<string.h>
#define SERVER_IP "192.168.1.71"
#define SERVER_PORT 8888
int main(int argc,char* argv[])
{
	int fd_client;
	struct sockadd_in server_addr;
	fd_client=socket(AF_INET,SOCK_STREAM,0);
	if(fd_client==-1)
	{
		perror("open");
		exit(-1);
	}
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=hton(SERVER_PORT);
	server_addr.sin_addr.s_addr=inet_addr(SERVER_IP);
	connect(fd_client,(struct sockaddr*)&server_addr,sizeof(server_addr));
	
	char* p="xuxiaoqiang!";
	send(fd_client,p,strlen(p),0);
	char buf[128]="";
	int recv_n
}
