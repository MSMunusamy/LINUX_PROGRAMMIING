/*******************************************/
/* Author	    : Munusamy M               */
/* Date		    : 22-2-2019                */
/* Filename 	: ipv4_client.h            */
/* Description	: socket client header     */
/*******************************************/

//include header files

#ifndef IPV4_CLIENT_H
#define IPV4_CLIENT_H

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<error.h>
#include<pthread.h>

void *send_fun();
void *recv_fun();

// user define datatype

#endif //socket_private_h


