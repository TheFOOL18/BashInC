#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE 15

#include "basic.h"

typedef struct queue{
    char* commands[QUEUE_SIZE];
    int size;
}queue;

queue* init_queue();

queue* enqueue(queue* q, char* command);

queue* clear_queue(queue* q);

void* show_queue(queue* q);

void free_queue(queue* q);

#endif