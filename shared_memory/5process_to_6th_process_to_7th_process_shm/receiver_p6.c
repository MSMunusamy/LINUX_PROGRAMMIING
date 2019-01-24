/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :receiver_p6.c        */
/* Description :collect all strings  */
/*             from p1,p2,p3,p4,p5   */
/*************************************/

#include"receiver_p6.h"

char buff1[8191]="";
char buff2[8191]="";
char buff3[8191]="";
char buff4[8191]="";
char buff5[8191]="";
char buff6[41290]="";
int main()
{
	int ret,i,j=0;
	mqd_t mqopen1,mqopen2,mqopen3,mqopen4,mqopen5,mpopen6;
	ssize_t recv;
	unsigned int prio;
	struct mq_attr my_attr;
	

	//mq_open is a systemcall its used to creates a new POSIX message queue or opens an existing queue
	mqopen1 =mq_open("/POSIX0",O_RDWR);
	perror("mq_open");
	
	//Receive the all messages using mq_receiver based on prority	
	recv=mq_receive(mqopen1,buff1,8192,&prio);
	perror("mq_receive");

	mq_getattr(mqopen1,&my_attr);
	strcpy(&buff6[0],buff1);
	
	//count the string and assign to one buffer
	for(i=0;buff1[i] !='\0';i++)
		j++;
		
	printf("%ld\n",my_attr.mq_msgsize);	
	printf("prority=>%u:%s \n",prio,buff1);	
	ret=mq_close(mqopen1);
	
	mqopen2 =mq_open("/POSIX1",O_RDWR);
	perror("mq_open");
	recv=mq_receive(mqopen2,buff2,8192,&prio);
	perror("mq_receive");
	mq_getattr(mqopen2,&my_attr);

	strcpy(&buff6[j],buff2);
	for(i=0;buff2[i] !='\0';i++)
		j++;
			
	printf("%ld\n",my_attr.mq_msgsize);	
	printf("prority=>%u:%s \n",prio,buff2);	
	ret=mq_close(mqopen2);
	
	mqopen3 = mq_open("/POSIX2",O_RDWR);
	perror("mq_open");
	recv=mq_receive(mqopen3,buff3,8192,&prio);
	perror("mq_receive");
	mq_getattr(mqopen3,&my_attr);

	strcpy(&buff6[j],buff3);
	for(i=0;buff3[i] !='\0';i++)
		j++;

	printf("%ld\n",my_attr.mq_msgsize);	
	printf("prority=>%u:%s \n",prio,buff3);	
	ret=mq_close(mqopen3);
	
	mqopen4 =mq_open("/POSIX3",O_RDWR);
	perror("mq_open");
	recv=mq_receive(mqopen4,buff4,8192,&prio);
	perror("mq_receive");
	
	mq_getattr(mqopen4,&my_attr);
	strcpy(&buff6[j],buff4);
	for(i=0;buff4[i] !='\0';i++)
		j++;
		
	printf("%ld\n",my_attr.mq_msgsize);	
	printf("prority=>%u:%s \n",prio,buff4);	
	ret=mq_close(mqopen4);
		
	mqopen5 =mq_open("/POSIX4",O_RDWR);
	perror("mq_open");
	recv=mq_receive(mqopen5,buff5,8192,&prio);
	perror("mq_receive");
	
	mq_getattr(mqopen5,&my_attr);
	strcpy(&buff6[j],buff5);
	for(i=0;buff5[i] !='\0';i++)
		j++;

	printf("%ld\n",my_attr.mq_msgsize);	
	printf("prority=>%u:%s \n",prio,buff5);
	         
        buff6[j]='\0';
	printf("%s\n",buff6);
	ret=mq_close(mqopen5);
       	perror("my_close:");
       
	//  system v shared memory segment
	int shmid1;
	char *data_ptr;
	shmid1=shmget(101,8192,IPC_CREAT |S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	
	//match the shared memory location 
	data_ptr=shmat(shmid1,NULL,0);
	perror("shmat");
	strcpy(data_ptr,buff6);
	
	//detaches  the  shared  memory 
	shmdt(data_ptr);
	perror("shmdt");
	return 0;
}
