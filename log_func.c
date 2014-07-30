/*	
 *	Linux下的syslog函数基本用法
 *
 * */
#include <stdio.h>
#include <syslog.h>

int main()
{
	//打开日志
	openlog("log_test",LOG_PID|LOG_CONS,LOG_USER);
	//写日志，级别为LOG_INFO
	syslog(LOG_INFO,"PID Information,pid=%d",getpid());
	//写日志，级别为LOG_DEBUG
	syslog(LOG_DEBUG,"debug message");
	//关闭日志
	closelog();
}
