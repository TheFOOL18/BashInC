#ifndef SPLIT_COMMAND_H
#define SPLIT_COMMAND_H

#include "basic.h"
#include "command.h"
#include "queue.h"

typedef struct queue queue;

void split_command(char* command, queue* q);

#endif