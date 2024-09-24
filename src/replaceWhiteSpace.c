#include <stdio.h>
#include <string.h>

void replaceWhiteSpace(char *str) {
    
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            str[i] = '+';
        }
    }
}
