#pragma once

#include "global.h"

/*
fonction "accept" pour pouvoir modifier le fd client

*/

void * accept_routine(void *arg)
{
    // "struct" client
    struct sockaddr_in client;
    socklen_t len;
    printf("ACCEPT ✅\n");

    pthread_t recv_thread;

    t_user utilisateur;

    for(int i = 0; i < MAX_USERS; i++) 
    {      
        int new_socket_client_fd = accept(serv_fd, (struct sockaddr*)&client, &len); perror("accept");  // fd = valeur tampon
        users[next_client_index].socket_fd = new_socket_client_fd;
        

        //users[i].room = 0; /// 0 == world

        next_client_index ++;
        pthread_create(&recv_thread, NULL, traitement_rcv, &users[i]);
    }    
    
    pthread_join(recv_thread,NULL);
}