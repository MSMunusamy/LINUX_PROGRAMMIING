/**************************************/
/*Author     : Munusamy M             */
/*Date       : 07-02-2019             */
/*Filename   : mutex.c                */
/*Description: mutex threading        */
/**************************************/

/* Included header files */

#include "mutex.h"

/* Global variable definitions*/

int global_var =0;

/* Mutex variable p_thread_mutex_t */

static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main()
{
     pthread_t thread1, thread2;
     
     int thread_create,arg;	
     
     /*Get a input from the user*/
     scanf("%d",&arg);
     
     /* Creating a thread1 using 'pthread_create',and call the threadFun with argument*/
     thread_create = pthread_create(&thread1, NULL, threadFun, &arg);
     perror("pthread");
     
     /* Creating a thread2 using 'pthread_create',and call the threadFun with argument*/
     thread_create = pthread_create(&thread2, NULL, threadFun, &arg);
     perror("pthread");
     
     /* Join the thread1 */
     thread_create = pthread_join(thread1,NULL);
     perror("pthread_join");

     /* Join the thread2 */
     thread_create  = pthread_join(thread2,NULL);
     perror("pthread_join");
     
     /* print the final global variable */
     printf("global_var = %d\n", global_var);
     perror("pthread_join");
}
void * threadFun(void *arg)
{
	int *loop = (int *) arg;
	int loc,j,var;
	 
	for(j=0; j<(*loop) ; j++)
	{
           /* pthread_mutex_lock is lock the thread when unlock appeared that munch time wait it will wait */		
	    var=pthread_mutex_lock(&mut);
	    
	    loc = global_var;
	    loc++;
	    
	    global_var=loc;
           
	    /* pthread_mutex_unlock is unlock the thread when lock appeared that munch time it will wait  */		
	    var=pthread_mutex_unlock(&mut);
        }
}
