/*
 *
 * 	IP地址的点分十进制和二进制之间互转
 * */
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
//#include <string.h>

int 
main(void)
{
	char addr_p[16]; /*IP地址的点分十进制字符串表示形式*/
	struct in_addr addr_n;/*IP地址的二进制表示形式*/
	/*地址由字符串转换为二进制数*/
	if(inet_pton(AF_INET,"192.168.11.6",&addr_n) < 0){
		perror("fail to convert");
		exit(1);
	}
	printf("address:0x%x\n",addr_n.s_addr);/*打印地址的16进制形式*/
	memset((char*)addr_p,0,sizeof(addr_p));
	/*地址由二进制数转换为点分十进制*/
	if(inet_ntop(AF_INET,&addr_n,addr_p,(socklen_t )sizeof(addr_p))==NULL){
		perror("fail to convert");
		exit(1);
	}
	printf("address:%s\n",addr_p);/*打印地址的点分十进制形式*/
	return 0;
}
