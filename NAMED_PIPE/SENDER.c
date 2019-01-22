
 ///////////////////////////////////    WRITTEN BY MUNUSAMY M    ////////////////////////////////////////   
                          
                      //////////////    DATE  22-01-2018        /////////////// 
                              //////////////////////////////////////   
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int retval;
	int fd,fd1;
	char buff[1000000];
	ssize_t ret_read,ret_write;

	//open is a syatem call
	fd=open("./17889_download_dj_snake_magenta_riddim_latest_english_ringtone_english_ringtones (1).mp3",O_RDONLY);
	//read is a system call
	ret_read = read(fd,buff,900000);
       	
	//open is a syatem call
	fd1   = open("PIPE",O_WRONLY);
	
	//write is a syatem call
       	ret_write=write (fd1,buff,900000);
        
	//close is a syatem call
	close(fd);
        close(fd1);
}
