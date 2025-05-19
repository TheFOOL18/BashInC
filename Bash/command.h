#ifndef COMMAND_H
#define COMMAND_H   

#include "basic.h"
#include "hop.h"
#include "reveal.h"
#include "queue.h"

typedef struct queue queue;

int execute_command(char* command, queue* q);

void process_command(char* command, queue*q, int type);

#endif