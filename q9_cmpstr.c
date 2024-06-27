// Write a C program to compare two strings (returns 0 on success and -1 on failure) Define above function in another c file (not in main source file)

#include <stdio.h>
#include "q9_compstr.c"  // Include the header file for the compare function

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