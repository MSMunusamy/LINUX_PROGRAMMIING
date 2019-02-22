 /**************************************/
 /*Author     : Munusamy M             */
 /*Date       : 07-02-2019             */
 /*Filename   : mutex.c                */
 /*Description: mutex threading        */
 /**************************************/

 /* Included header files */
 #include"clientsocket.h"

 /*Global variable definitions*/ 

 /*Function definitions*/

 int main()
 {
	char str1[]="MESSAGE FROM CLIENT";
	int socket_fd1;
	struct sockaddr_un unix_addr;


	unix_addr.sun_family = AF_UNIX;
	strcpy(unix_addr.sun_path,"./socket1");

	//opening a unix socket,with DGRAM type protocol

	socket_fd1 =socket(AF_UNIX,SOCK_DGRAM,0);


	//sending first message 

	sendto (socket_fd1,str1,strlen(str1)+1,0,(struct sockaddr*)&unix_addr,sizeof(unix_addr));
	
        sleep(2);
        
	//socket will be closed

	close (socket_fd1);
}	
