#pragma once

#include "global.h"

/*
fonction "accept" pour pouvoir modifier le fd du client
*/

void * accept_routine(void *arg)
{
    
    struct sockaddr_in client;
    socklen_t len;
    //printf("ACCEPT ✅\n");

    pthread_t recv_thread;

    t_user utilisateur;

    while(1)
    {      
        int new_socket_client_fd = accept(serv_fd, (struct sockaddr*)&client, &len); perror("accept");
        // gestion des erreurs en cas de fail de la boucle 
        users[next_client_index].socket_fd = new_socket_client_fd;
        next_client_index ++;
        pthread_create(&recv_thread, NULL, traitement_rcv, &users[next_client_index]);
    }    
    
    pthread_join(recv_thread,NULL);
}