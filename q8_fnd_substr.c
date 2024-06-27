// Write a C program to find keyword/substring from a given string. If substring is available print "Search successful" otherwise print "Search Unsuccessful"

#include <stdio.h>

int main()
{
    char str[100], str1[100];
    int flag = 0, cnt1 = 0, cnt2 = 0;

    // Prompt user to enter the main string
    printf("Enter String: ");
    gets(str);

    int len1 = strlen(str);

    if(len1 == 0)
    {
        printf("Empty main string detected...\n");
        flag = 0;
    }

    int space1 = 0;
    for(int i = 0; i <= len1; i++){
        if(i == ' '){
            space1++;
        }
    }
    if(space1 = len1){
        flag = 0;
        printf("Just entering spaces won't work...\n");
    }

    // Prompt user to enter the string to search
    printf("Enter string to search: ");
    gets(str1);

    int len2 = strlen(str1);

    if(len2 == 0)
    {
        printf("Empty find string detected...\n");
        flag = 0;
    }

    int space2 = 0;
    for(int i = 0; i <= len2; i++){
        if(i == ' '){
            space2++;
        }
    }
    if(space2 = len2){
        flag = 0;
        printf("Just entering spaces won't work...\n");
    }

    // // Calculate the length of the main string
    // while (str[cnt1] != '\0')
    // {
    //     cnt1++;
    // }

    // // Calculate the length of the search string
    // while (str1[cnt2] != '\0')
    // {
    //     cnt2++;
    // }

    // Perform substring search
    for (int i = 0; i <= len1 - len2; i++)
    {
        flag = 1; // Assume substring match initially

        // Compare each character in the substring
        for (int j = 0; j < len2; j++)
        {
            if (str[i + j] != str1[j])
            {
                flag = 0; // Reset flag if characters don't match
                break;
            }
        }

        // If the flag is still 1, the substring is found
        if (flag == 1)
        {
            break;
        }
    }

    // Display search result
    if (flag == 1)
    {
        printf("Search successful\n");
    }
    else
    {
        printf("Search unsuccessful\n");
    }

    return 0;
}
