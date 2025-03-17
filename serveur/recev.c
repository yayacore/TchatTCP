#pragma once

#include "global.h"

/*
recv des clients en boucle 
+ traitement des erreurs
*/

void * traitement_rcv(void *arg)
{
    //printf("RECV ✅\n");
    
    // transtypage void* arg en int
    t_user client = *((t_user*) arg);   
    t_message colis;
    
    while(1) 
    {

        int nb_datas = recv(client.socket_fd, &colis, sizeof(t_message), 0); perror("rcv"); 

            
        if(nb_datas == -1)
        {
            printf("erreur aucune donnée n'a été récupérée//\n");
            continue;
        }
        
        if(nb_datas == 0)
        {
            printf("user gone  :'(\n");
            break;
        }
            
        for(int i = 0; i < next_client_index; i++) 
        {
        
            //printf("SEND ✅\n");
            send(users[i].socket_fd, &colis, sizeof(t_message), 0); perror("send");
        }
        
        printf("[%s]> %s \n", colis.name, colis.message);

        printf("nombre de clients présents : %d\n", next_client_index);
    }
}