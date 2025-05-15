#include "split_command.h"

void split_command(char* command){
    char* command_copy = strdup(command);
    char* start = command_copy;
    char*end = start;

    while(true){
        if(*end == ';'){
            *end = '\0';
            process_command(trim(start), 0);
            start = end + 1;
        }

        else if(*end == '&'){
            *end = '\0';
            process_command(trim(start), 1);
            start = end + 1;
        }

        else if(*end == '\0'){
            process_command(trim(start), 0);
            break;
        }
            
        end++;
    }
    free(command_copy);
}