#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int retval;
	//creating for named PIPE
	retval=mknod("PIPE",0644 | S_IFIFO,0);
	
	printf("%d\n",retval);
}
