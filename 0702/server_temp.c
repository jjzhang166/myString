/*************************************************************************
	> File Name: server_temp.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月02日 星期三 23时40分51秒
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
int main()
{
	int temp;
	int fd_server;
	int fd_client;
	//生成一个套接字描述符
	fd_server=socket(AF_INET,SOCK_STREAM,0);//最后面的那个参数会自己判断
	if(fd_server==-1)
	{
		perror("error!");
		exit(-1);
	}
	//绑定【把一个IP地址和端口号绑定上socket上面去】
	//bind函数的原型问题
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	//结构体的成员赋值
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);//端口号的网络字节序
	server_addr.sin_addr.s_addr=inet_addr(IP);//点分十进制转化为网络字节序
	
	temp=bind(fd_server,(const struct sockaddr*)&server_addr,sizeof(server_addr));//之所以第二个参数需要强制类型转换，一方面二者的大小相等，另一个
	//bind的返回值是个int
	//
	//监听过程
	//int listen(int sockfd,int backlog);最后一个参数是监听队列的长度
	if(temp==-1)
	{
		printf("binding failure\n");
	}
	printf("testing listen\n");
	temp=listen(fd_server,5);
	if(temp==-1)
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}
	//accept函数  取链接
	//accept(sockfd,struct sockaddr *addr,socklen_t *addrlen);对面的消息就保存在addr中
	//accept返回客户端描述符
	struct sockaddr_in client_addr;//对方
	int len=sizeof(client_addr);
	fd_client=accept(fd_server,(struct sockaddr*)&client_addr,&len);//accepty也是个阻塞函数   fd_server此时只负责去连接，接下来真正起作用的是fd_client

	char receive_buf[128]="";
	int recv_n;
	printf("testing\n");
	recv_n=recv(fd_client,receive_buf,128,0);//rece最后面的一个参数时flag
	printf("receive from IP:%s\nMsg:%s\nLen:%d\n",inet_ntoa(client_addr.sin_addr),receive_buf,recv_n);
	int send_n=send(fd_client,receive_buf,recv_n,0);
	printf("sent to IP:%s\nMsg:%s\nLen:%d\n",inet_ntoa(client_addr.sin_addr),receive_buf,recv_n);
	return 0;
}
