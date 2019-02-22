/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :ls_header1.h         */
/* Description :header file          */
/*                                   */
/*************************************/

/* Included header file  */

#include  "serversocket.h"
/*Global variable definitions*/

/*Function definitions*/

int main(int argc,char *argv[])
{
	int socket_fd1;
	struct sockaddr_in socketaddr;
	unsigned char str1[200];
	unsigned int ipv4;
	
	socklen_t length = sizeof(struct sockaddr_in);
	
	/*opening a unix socket,with DGRAM type protocol and create a socket ,socket is a end point communication*/
	socket_fd1 =socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");
        
	/*memset fill memory with a contant byte*/
	memset(&socketaddr,0,sizeof(struct sockaddr_in));
	perror("memset");
        
	socketaddr.sin_family = AF_INET;
	
	/* htonl, htons, ntohl, ntohs - convert values between host and network byte order*/
	socketaddr.sin_port =   htons(atoi(argv[1]));
	
	/*convert IPv4 and IPv6 addresses from text to binary form */
	ipv4 = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr);
	perror("inet_pton");
	
	/*binding with 'socket1'socket file */
	bind (socket_fd1,(struct sockaddr *)&socketaddr,sizeof(socketaddr));

	/*receiving a first message */
	recvfrom (socket_fd1,str1,100,0,(struct sockaddr*)&socketaddr,&length);

	printf("%s \n",str1);
	
	/*socket will be closed */
	close (socket_fd1);
}
