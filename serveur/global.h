#pragma once

#define MAX_USERS 50
//int users[MAX_USERS];

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
// #include <dirent.h> // listing des fichiers
// #include <fcntl.h>  // gérer ls fichiers
#include <sys/stat.h> 
#include <pthread.h> // pr ls threads
#include <errno.h>

int serv_fd; 
int next_client_index = 0;

typedef struct user {
    char name[255];
    int socket_fd;
    int id_room;
}t_user;

t_user users[MAX_USERS];

typedef struct message {
    char name[255];
    int id_room;        //tag du salon
    char message[1000];
}t_message;

//fichiers avec toutes les fonctions
#include "socket.c"
#include "recev.c"
#include "accept.c"