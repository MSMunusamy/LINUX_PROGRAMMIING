/*******************************************/
/* Author	: Munusamy M                   */
/* Date		: 22-2-2019                    */
/* Filename	: internet_ipv4_server.c       */
/* Description	: socket                   */
/*******************************************/

/* Included header file */

#include "internet_ipv4_client.h"

/* Global variable definitions */

unsigned char str1[500],str2[500];
struct sockaddr_in socketaddr;
int worker,p_1,p_2;
socklen_t length = sizeof(struct sockaddr_in);

/* function definitions */
 
int main(int argc,char *argv[])
{
	pthread_t love_thread_1,love_thread_2;

	unsigned int ip_v4;

	/* socket - create an endpoint communication refer to " man socket " */
	worker=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");


	/* memset - fill memory with a constant byte refer to  " man memset " */
	memset(&socketaddr, 0, sizeof(struct sockaddr_in));
	socketaddr.sin_family =AF_INET;

	/* htonl,  htons,  ntohl, ntohs - convert values between host and net‐work byte order refer to " man htons " */
	/* atoi, atol, atoll - convert a string to an intege refer to " man atoi "*/
	socketaddr.sin_port  = htons(atoi(argv[1]));

	/* inet_pton  -  convert  IPv4  and IPv6 addresses from text to binary form refer to " man inet_pton " */
	ip_v4 = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr);
	
    /* send, sendto, sendmsg - send a message on a socket refer to " man sendto "*/
	while(1)
	{
	/* pthread_create - create a new thread refer to " man pthread_create "*/
	p_1=pthread_create(&love_thread_1,NULL,fun_2,NULL);

	/* pthread_create - create a new thread refer to " man pthread_create "*/
	p_2=pthread_create(&love_thread_2,NULL,fun_1,NULL);
	}

}

void *fun_1()
	{
	scanf("%[^\n]%*c",str1);
	/* recv, recvfrom, recvmsg - receive a message from a socket refer to "  man recvfrom "*/
	sendto(worker, str1,strlen(str1)+1, 0,(struct sockaddr *)&socketaddr, sizeof(socketaddr));
	}

void *fun_2()
	{
	 /* send, sendto, sendmsg - send a message on a socket refer to " man sendto "*/
	 recvfrom(worker, str2,100, 0,(struct sockaddr *)&socketaddr, &length);
	 printf("%s\n",str2);
    }
