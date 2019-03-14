/**************************************/
/*Author     : Munusamy M             */
/*Date       : 07-02-2019             */
/*Filename   : mutex.c                */
/*Description: mutex threading        */
/**************************************/

#include "header_lib.h"
int a,b;
int main()
{
	printf("Enter Your input\n");
        scanf("%d %d",&a,&b);
        addition(a,b);
	subtract(a,b);
	return 0;
}
