#ifndef LOG_H
#define LOG_H

#include "basic.h"
#include "queue.h"
#include "split_command.h"

typedef struct queue queue;

void init_log(queue* q);

void write_log(queue* q);

void process_log(char* command, queue* q);
#endif