#include <stdio.h>
#include <string.h>

// Function to compare two strings
int strComp(const char *str1, const char *str2) {
    if(strcmp(str1, "") == 0 || strcmp(str2, "") == 0){
        printf("Empty String...");
        return -1;
    }

    return strcasecmp(str1, str2);
}