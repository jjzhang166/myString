/*************************************************************************
	> File Name: client.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月02日 星期三 16时35分21秒
 ************************************************************************/

#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#define SERVER_IP "192.168.1.138"
#define SERVER_PORT 8888
int main()
{
	int fd_client;
	struct sockaddr_in server_addr;
	fd_client=socket(AF_INET,SOCK_STREAM,0);
	if(fd_client==-1)
	{
		perror("open");
		exit(-1);
	}
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(SERVER_PORT);
	server_addr.sin_addr.s_addr=inet_addr(SERVER_IP);
	connect(fd_client,(struct sockaddr*)&server_addr,sizeof(server_addr));//涉及到的三次握手就在这个函数中实现的
	
	char name[20];
	int fd_load;
	int recv_n;
	char buf[128];
	printf("input the name:");
	fgets(name,20,stdin);
	fd_load=open("a.txt",O_WRONLY|O_CREAT,0666);
	if(fd_load==-1)
	{
		perror("open error\n");
		exit(-1);
	}
	send(fd_client,name,strlen(name),0);
	//int recv_n=recv(fd_client,buf,128,0);
	while(memset(buf,0,128),(recv_n=recv(fd_client,buf,128,0))>0)
	{
		write(fd_load,buf,recv_n);
	}
	close(fd_load);



	//char* p="hello world!";
	//send(fd_client,p,strlen(p),0);//0代表的不延迟，立即发送
	//和服务器的连接的建立就是在这里进行的
	//char buf[128]="";
	//int recv_n=recv(fd_client,buf,128,0);
	//printf("recv from ip:port %s:%d\nMSG:%s\nLEN:%d\n",inet_ntoa(server_addr.sin_addr),server_addr.sin_port,buf,strlen(buf));
	return 0;
	//connect函数的关系
}
/*
 * */

