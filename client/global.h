#pragma once

#define MAX_USERS 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <pthread.h> 
#include <errno.h>

int serv_fd;
int compteur_clients = 0;

typedef struct user
{
    char name[255];
    int fd;
    int id_room;
} t_user;

t_user users[MAX_USERS];

typedef struct message
{
    char name[255];
    int id_room; // tag du salon
    char message[1000];
} t_message;

#include "socket.c"
#include "send.c"
#include "recev.c"