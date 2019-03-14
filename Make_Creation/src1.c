/**************************************/
/*Author     : Munusamy M             */
/*Date       : 14-03-2019             */
/*Filename   : src1.c                */
/*Description: Main_function          */
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
