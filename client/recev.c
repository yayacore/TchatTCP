#pragma once 

#include "global.h"

void * recv_routine(void *arg)
{
    while(1)
    {
        
        t_user client = *(t_user*)arg;
        t_message courrier;
      
        int error = recv(client.fd, &courrier, sizeof(t_message), 0); perror("recv");
        if(error == -1) printf("erreur\n");

        printf("%s : %s\n", courrier.name, courrier.message);
    }
}