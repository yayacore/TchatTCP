#pragma once 

#include "global.h"

/*
envoi au serveur
*/

void * send_routine(void *arg)
{

   t_user client = *(t_user*)arg;
   
   t_message colis; 

   strcpy(colis.name, client.name);
   
   
   while(1) {
       
        char buf[255]; 
        fgets(buf, sizeof(buf), stdin);

        buf[strlen(buf)-1] = 0;     // rm \n
        
        // je téléverse les données du bufer dans le char message de ma struct client
        strcpy(colis.message, buf);

        /*
        envoi du colis à la bonne adresse avec la bonne taille de struct 
        */

        int error = send(client.fd, &colis, sizeof(t_message), 0); perror("send");
        //printf("%s: %s \n",colis.name, colis.message);
        if (error == -1) printf("problème survenu lors de l'envoi \n"); 
        
        memset(buf, 0, 255);
    }


}