/*************************************************************************
	> File Name: gethostbyname.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月02日 星期三 14时55分05秒
 ************************************************************************/

#include<stdio.h>
#include<netdb.h>
int main(int argc,char* argv[])
{
	struct hostent* my_ent;  
	char str[32]={'\0'};
	char *ptr,**pptr;
	if(argc==1)
	{
		my_ent=gethostbyname("localhost");
	}
	else
	{
		my_ent=gethostbyname(argv[1]);
	}
	//my_ent=gethostbyname(argv[1]);
	//将主机的规范名打出来
	printf("host_name:%s \n",my_ent->h_name);
	//list中的二级指针序列的应用  取结构体中的信息
	for(pptr=my_ent->h_aliases;*pptr!=NULL;pptr++)
	{
		printf("alias:%s\n",*pptr);
	}
	//将地址打印出来D
	for(pptr=my_ent->h_addr_list;*pptr!=NULL;pptr++)
	{
		printf("%x",*(int*)*pptr);
		printf("\n");
	}
	return 0;
}

