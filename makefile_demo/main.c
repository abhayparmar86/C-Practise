#include <stdio.h>
#include "strcomp.h"

int main()
{
    char str1[100], str2[100];

    // Prompt the user to enter the first string
    printf("Enter string 1: ");
    gets(str1);

    // Prompt the user to enter the second string
    printf("Enter string 2: ");
    gets(str2);

    int result = strComp(str1, str2);

    if (result == 0)
    {
        printf("Strings are equal.\n");
    }
    else
    {
        printf("Strings are not equal.\n");
    }

    return 0;
}