#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<error.h>
int main()
{
	int retval;
	int fd,fd1;
	char buff[1000000];
	ssize_t ret_read,ret_write;
	
	//open is  system call 
	fd=open("PIPE",O_RDONLY);
	perror("open :");
	
	//read is  system call 
	ret_read = read(fd,buff,900000);
	perror("read :");
	
	//open is  system call 
	fd1=open("anu.mp3",O_CREAT | O_WRONLY,0764);
	perror("open :");

	
	//write is  system call 
	ret_write = write(fd1,buff,900000);
	perror("close :");
	
	close(fd);
	close(fd1);
}
