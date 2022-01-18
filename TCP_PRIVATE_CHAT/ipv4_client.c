/*******************************************/
/* Author	    : Munusamy M           */
/* Date		    : 22-2-2019            */
/* Filename 	: ipv4_client.c            */
/* Description	: socket client program    */
/*******************************************/

#include "ipv4_client.h"

	int socket_fd;
	int s1,s2;
	struct sockaddr_in socketaddr;
	unsigned char str[9091], str1[9091];

	socklen_t length = sizeof(struct sockaddr_in);

int main(int argc,char *argv[])
{
	pthread_t t1,t2;
	socket_fd=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");

	socketaddr.sin_family =AF_INET;
	socketaddr.sin_port  = htons(atoi(argv[1]));

	unsigned int ip = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr);
	while(1)
	{
		s1 = pthread_create(&t1,NULL,send_fun,NULL);
		s2 = pthread_create(&t2,NULL,recv_fun,NULL);
	}
	close(socket_fd);
}
void *send_fun()
{
	scanf("%[^\n]%*c",str1);

	sendto(socket_fd, str1,strlen(str1)+1, 0,(struct sockaddr *)&socketaddr, sizeof(socketaddr));

}
void *recv_fun()
{
	recvfrom(socket_fd,str,8080,0,(struct sockaddr *)&socketaddr,&length);
	printf("%s\n",str);

}
