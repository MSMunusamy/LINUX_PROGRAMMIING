/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :receiver_p6.c        */
/* Description :collect all strings  */
/*             from p1,p2,p3,p4,p5   */
/*************************************/

#include "ls_header.h" 

int main()
{
       DIR *ptr;
       struct dirent *ls;
       
       //The  opendir()  function  opens  a directory stream corresponding to the directory name 
       ptr = opendir("/home/geeks/linux_programming");
       perror("opendir");

       //The  readdir()  function returns a pointer to a dirent structure 
       ls = readdir(ptr);
       perror("readdir");
       
       //It returns NULL on reaching  the  end  of  the  directory  stream or if an error occurred so only 
       //given !=NULL because need to print all directory and files

       for( ;  ls !=NULL;  )
       {
         //skip . and .. 
	  if(strcmp(ls->d_name,".")!=0&&strcmp(ls->d_name,"..")!=0) 
	     printf("%s \t ",ls->d_name);
             ls = readdir(ptr);
       }
       perror("\n closedir");
}
