/*******************************************/
/* Author	: Munusamy M                   */
/* Date		: 22-2-2019                    */
/* Filename	: internet_ipv4_server.c       */
/* Description	: socket                   */
/*******************************************/

/* Included header file */

#include "internet_ipv4_server.h"

/* Global variable definitions */
	socklen_t length = sizeof(struct sockaddr_in);
	unsigned int ip_v4;
	unsigned char str1[500],str2[500];
	struct sockaddr_in socketaddr;
	int server,p_1,p_2;
	
/* function definitions */
 
int main(int argc, char *argv[])
{

	pthread_t thread_1,thread_2;

	/* socket - create an endpoint for communication refer to " man socket " */
	server=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");

	/* memset - fill memory with a constant byte  refer to " man memset " */
	memset(&socketaddr, 0, sizeof(struct sockaddr_in));

	socketaddr.sin_family =AF_INET;
	socketaddr.sin_port  = htons(atoi(argv[1]));

	/* inet_pton  -  convert  IPv4  and IPv6 addresses from text to binary form refer to " man inet_pton " */
	ip_v4 = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr);

	/*bind - bind a name to a socket :: REFERENC IN " man bind "  */
	bind(server,(struct sockaddr *)&socketaddr,sizeof(socketaddr));
	perror("bind");
	/* recv, recvfrom, recvmsg - receive a message from a socket refer to man recvfrom " */
	while(1)
	{
	/* pthread_create - create a new thread  refer to " man pthread_create "*/
	p_1=pthread_create(&thread_1,NULL,fun_2,NULL);
	/* pthread_create - create a new thread refer to " man pthread_create "*/
	p_2=pthread_create(&thread_2,NULL,fun_1,NULL);
	}
	
}
		
void *fun_1()
	{
	/* recv, recvfrom, recvmsg - receive a message from a socket refer to "  man recvfrom "*/	
	recvfrom(server, str1,100, 0,(struct sockaddr *)&socketaddr, &length);
	printf("%s\n",str1);
	}

void *fun_2()
	{
	scanf("%[^\n]%*c",str2);
	/* send, sendto, sendmsg - send a message on a socket refer to " man sendto "*/
	sendto(server, str2,strlen(str2)+1, 0,(struct sockaddr *)&socketaddr, sizeof(socketaddr));
} 
