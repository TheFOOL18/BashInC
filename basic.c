#include "basic.h"

char* trim(char* str){
    int len = strlen(str);
    char* end = str + len - 1;
    int idx = 0;
    while(idx < len && (str[idx] == ' ' || str[idx] == '\t')){
        str++;
    }
    while(end > str &&(end[idx] == ' ' || end[idx] == '\t' )){
        end--;
    }
    end[1] = '\0';
    return str;
}