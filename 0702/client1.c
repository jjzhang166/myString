/*************************************************************************
	> File Name: client1.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月02日 星期三 00时57分50秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<stdlib.h>
int main()
{
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch='A';
	//为客户创建一个套接字
	sockfd=socket(AF_UNIX,SOCK_STREAM,0);
	//根据服务器的情况给套接字命名
	address.sun_family=AF_UNIX;
	strcpy(address.sun_path,"server_socket");
	len=sizeof(address);
	//将我们的套接字连接到服务器的套接字
	result=connect(sockfd,(struct sockaddr *)&address,len);
	if(result==-1)
	{
		perror("oops:client1");
		exit(1);
	}
	//现在可以用套接字进行读写啦
	write(sockfd,&ch,1);
	read(sockfd,&ch,1);
	printf("char from server=%c\n",ch);
	close(sockfd);
	exit(0);
}
