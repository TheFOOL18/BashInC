#include "basic.h"

char* previous_directory = NULL;
char* log_path = NULL;

char* trim(char* str) {
    if (str == NULL)
        return str;
    
    while (*str == ' ' || *str == '\t')
        str++;

    char* output = (char*)malloc(strlen(str) + 1);
    strcpy(output, str);

    if (*output == '\0')
        return output;

    char* end = output + strlen(output) - 1;
    while (end > output && (*end == ' ' || *end == '\t'))
        end--;

    *(end + 1) = '\0';
    return output;
}
