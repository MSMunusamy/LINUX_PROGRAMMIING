/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :receiver_p6.c        */
/* Description :send  a given string */
/*               process6            */
/*************************************/

#include "process_1.h"

char message1[]="Hai i am First Process\n";
int main()
{
	int ret;
	mqd_t mqopen;
	struct mq_attr my_attr;
	
	my_attr.mq_maxmsg=100; 	//max number of message in queue
	my_attr.mq_msgsize=1024;//max size of message
        
	//mq_open is a systemcall its used to creates  a  new POSIX message queue or opens an existing queue
	mqopen=mq_open("/POSIX0",O_CREAT |O_RDWR,0644,NULL);
        perror("mq_open:");
       
       	//send a message to a message queue
	ret=mq_send(mqopen,message1,strlen(message1)+1,100);
        perror("mq_send:");
        
	//close a message queue descriptor
	ret=mq_close(mqopen);
	perror("mq_close:");	
}
