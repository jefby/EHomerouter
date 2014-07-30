/*
 *	hostent结构和gethostbyname函数的基本使用方法示例
 *	struct hostent {
 *	  char  *h_name;//规范名
 *	  char  **h_aliases;//别名
 *	  int   h_addrtype;//地址类型，AF_INET | AF_INET6
 *	  int   h_length;//主机IP地址的长度
 *	  char  **h_addr_list;//主机的IP地址,以网络字节序存储不能直接打印
 *	};
 *	根据域名返回IP地址
 */
#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	 char **pptr;
	 struct hostent *hptr;
	 char str[32];//便于存储字符串形式的IP地址，兼容IPV6地址
	 /* argv[1]，即要解析的域名或主机名 */
	 if(argc != 2){//确保参数个数为2
		printf("usage : ./a.out ip/host\n");
		exit(-1);
	 }
	 /* 调用gethostbyname()。调用结果都存在hptr中 */
	 if( (hptr = gethostbyname(argv[1]) ) == NULL )
	 {
		printf("gethostbyname error for host:%s\n",argv[1]);
		return -2; /* 如果调用gethostbyname发生错误，返回1 */
	 }
	 /* 将主机的规范名打出来 */
	 printf("official hostname:%s\n",hptr->h_name);
	 /* 主机可能有多个别名，将所有别名分别打出来 */
	 for(pptr = hptr->h_aliases; *pptr != NULL; pptr++)
	  	printf("alias:%s\n",*pptr);
	 /* 根据地址类型，将地址打出来 */
	 switch(hptr->h_addrtype)
	 {
	  case AF_INET:
	  case AF_INET6:
	  	pptr=hptr->h_addr_list;
	   	/* 将刚才得到的所有地址都打出来。其中调用了inet_ntop()函数,将网络字节序转换为主机序的字符串IP地址,并存储在str字符串中 */
	   	for(;*pptr!=NULL;pptr++)
	    		printf("address:%s\n", inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
	  break;
	  default:
	  	printf("unknown address type\n");
	  break;
	 }
	 return 0;
}
