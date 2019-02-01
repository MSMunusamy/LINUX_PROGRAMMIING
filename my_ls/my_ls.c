/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :my_ls.c              */
/* Description :like ls command      */
/*              program              */
/*************************************/

/* Included header file  */

#include "ls_header1.h" 

/*Global variable definitions*/

/*Function definitions*/

struct dirent *data1,*data;//inode_no. directory_name serial_no. name_of_entry placed in dirent structure

int main(int argc,char *dat[])
{
       int a=0,b=0;
       DIR *dir,*dir1; //DIR datatype represents a data stream
       char  *ptr,*ptr1 ;
       ptr=dat[1];
       
       if(argc==1)//condition if equal it will show current directory all files
       {
       	          //The  opendir()  function  opens  a directory stream corresponding to the directory name 
	       dir=opendir(".");
	       perror("opendir");
       }    
       else if(argc>1)
       {         
	    dir=opendir(ptr);   
            if(dir==0)	
	     {
                printf("No such file or Directory");
	        exit(0);
             }
       }
       data1=readdir(dir);  
       perror("readdir");
  
       //if data1 returns NULL pointer,that is end of the directory entry 
       for( ;  data1 !=NULL;  )
            {     
  
                 //skip . and .. directories
		 if(strcmp(data1->d_name,".")!=0&&strcmp(data1->d_name,"..")!=0) 
	         
		 printf("%s \n ",data1->d_name);
		 data1= readdir(dir);//If success,readdir() returns a pointer of type struct dirent
            }
       closedir(dir);
       return 0;
}
