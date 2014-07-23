/*************************************************************************
	> File Name: server_exe.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月03日 星期四 00时15分07秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define IP "192.168.1.71"
#define PORT 8888
int main(int argc,char* argv[])
{
	int fd_server;
	int fd_client;
	struct sockaddr_in server_addr;
	int temp;
	//1、建立套接字
	fd_server=socket(AF_INET,SOCK_STREAM,0);
	if(fd_server==-1)
	{
		perror("create fd_server");
		exit(-1);
	}
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=inet_addr(IP);
	//2、绑定套接字
	temp=bind(fd_server,(struct sockaddr*)&server_addr,sizeof(server_addr));
	if(temp==-1)
	{
		printf("binding error\n");
		exit(-1);
	}
	//3、监听
	temp=listen(fd_server,5);
	if(temp==-1)
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}
	//4、accept
	struct sockaddr_in client_addr;//用户记录信息的东东
	fd_client=accept(fd_server,(struct sockaddr*)&client_addr,strlen(client_addr));
	if(fd_client==-1)
	{
		perror("accept error");
		close(fd_server);
		exit(-1);
	}
	//5、receive
	char receive_buf[128]="";
	char send_buf="hell,world";
	int recv_n;

	recv_n=recv(fd_client,receive_buf,128,0);
	printf("receive from IP:%s\nMSG:%s\n",inet_ntoa(client_addr.sin_addr),receive_buf);
	int send_n=send(fp_client,send_buf,strlen(send_buf),0);
	printf("sent to IP:%s\nMsg:%s\n",inet_ntoa(client_addr.sin_addr),send_buf,strlen(send_buf));
	close(fd_server);
	close(fd_client);
	return 0;
	
}

