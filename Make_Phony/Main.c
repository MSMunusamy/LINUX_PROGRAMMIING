/**************************************/
/*Author     : Munusamy M             */
/*Date       : 14-03-2019             */
/*Filename   : Main.c                 */
/*Description: Main Function          */
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
