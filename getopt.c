#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc,char **argv)
{
	int opt = 0;
	while((opt=getopt(argc,argv,"n:c:e")) != -1){//optstring="n:c:e"
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

