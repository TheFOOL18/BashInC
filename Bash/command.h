#ifndef COMMAND_H
#define COMMAND_H   

#include "basic.h"
#include "hop.h"
#include "reveal.h"

int execute_command(char* command);

void process_command(char* command, int type);

#endif