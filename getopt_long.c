#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc,char **argv)
{
	static struct option mylongopt[]={
                {"name",required_argument,NULL,'n'},
                {"company",required_argument,NULL,'c'},
                {"echo",no_argument,NULL,'e'},
                {NULL,0,NULL,0}
        };

	int opt = 0;
	while((opt=getopt_long(argc,argv,"",&mylongopt,NULL)) != -1){// 只允许使用长参数
		switch(opt){
			case 'n':
				printf("name is %s\n",optarg);
			break;
			case 'c':
				printf("company is %s\n",optarg);
			break;
			case 'e':
				printf("echo\n");
			break;
			case '?':
				printf("argumnet is error.\n");
				return -1;
		}
	}
        return 0;
}

