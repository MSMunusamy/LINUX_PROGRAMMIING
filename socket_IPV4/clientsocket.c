 /*************************************/
 /* Author      :Munusamy M           */
 /* Date        :22-01-2019           */
 /* Filename    :ls_header1.h         */
 /* Description :header file          */
 /*                                   */
 /*************************************/

/* Included header file  */

#include "clientsocket.h"

/*Global variable definitions*/

/*Function definitions*/

int main(int argc,char *argv[])
{
int client;
unsigned int ipv4;
struct sockaddr_in socketaddr;

/* write some message in string */
unsigned char str1[]="IPV4 SOCKET FROM CLIENT";
socklen_t length = sizeof(struct sockaddr_in);

/* socket - create an endpoint for communication  */
client=socket(AF_INET,SOCK_DGRAM,0);
perror("socket");

/* memset - fill memory with a constant byte  */
memset(&socketaddr, 0, sizeof(struct sockaddr_in));
socketaddr.sin_family =AF_INET;

/* htonl,  htons,  ntohl, ntohs - convert values between host and net‐work byte order */
/* atoi, atol, atoll - convert a string to an integei*/
socketaddr.sin_port  = htons(atoi(argv[1]));

/* inet_pton convert  IPv4  and IPv6 addresses from text to binary form  */
ipv4 = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr);

/* send, sendto, sendmsg send a message on a socket */
sendto(client, str1,strlen(str1)+1, 0,(struct sockaddr *)&socketaddr, sizeof(socketaddr));
perror("sendto");

sleep(5);/*waiting time delay */
close(client);
}
