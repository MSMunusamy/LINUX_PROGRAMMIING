/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :receiver_p6.c        */
/* Description :process_6 have string*/
/*              send to process_7    */
/*************************************/

#include"receiver_p7.h"

char message1[]="MESSAGE FROM PROCESS 1\n";
int main()
{
	int shmid1;
	char data[500000];
	char *data_ptr;
	shmid1=shmget(101,8192,0);
       
	//attaches  the  System V shared memory segment
	data_ptr=shmat(shmid1,NULL,0);
	perror("shmat");
        
	//copy a string source to destination	
	strcpy(data,data_ptr);
	
	printf("%s\n",data);
	shmdt(data_ptr);
	perror("shmdt");
	return 0;
}
