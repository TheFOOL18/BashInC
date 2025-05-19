#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE 5

#include "basic.h"
#include "log.h"

typedef struct queue{
    char* commands[QUEUE_SIZE];
    int size;
}queue;

queue* init_queue();

queue* enqueue(queue* q, char* command);

queue* pop(queue* q);

queue* clear_queue(queue* q);

void* show_queue(queue* q);

void free_queue(queue* q);

#endif