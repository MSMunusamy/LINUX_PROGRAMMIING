/**************************************/
/*Author     :Munusamy M              */
/*Date       :06-02-2019              */
/*Filename   :pthread.c               */
/*Description:Creation of thread      */
/**************************************/

#include"pthread.h"

/* Macro Definitions */

void *threadfun(void *);

/* User defined datatype definitions */

int main()
{
/*Function definitions*/
	int inp,var;
        pthread_t thread_create;
	
	//Get a input from user 
	scanf("%d",&inp);	
        
	//pthread_create is a system call used to create a thread
	var=pthread_create(&thread_create,NULL,threadfun,&inp);
	
	//Function call
	threadfun(&inp);
}	
void *threadfun(void *inp1)
{
	//Type casting 
	int *get_data=(int *)inp1;
	int i;
	
	//until fail a condition loop will execute 
	for(i=1;i<=(*get_data);i++)
		printf("%d\n",i);
}
