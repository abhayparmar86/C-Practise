// Write a C program that expands given short norm to expanded string. e.g., if passed string is "a-g" output should be "abcdefg" if passed string is "b-h4-8" output should be "bcdefgh45678" if passed string is "-c-e-" output should be "cde

#include <stdio.h>

// Function to check if a character is an alphabet
int isAlphabet(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to expand a short form string (for alphabets only)
void expandAlphabets(char inpstr[], char outstr[])
{
    int i = 0, j = 0;

    // Loop through the input string
    while (inpstr[i] != '\0')
    {
        if (isAlphabet(inpstr[i]))
        {
            // Copy alphabet characters to the output string
            outstr[j++] = inpstr[i];
        }
        else if (inpstr[i] == '-' && i > 0 && inpstr[i + 1] != '\0' && isAlphabet(inpstr[i - 1]) && isAlphabet(inpstr[i + 1]))
        {
            // Handle the short form (e.g., a-g)
            char strt = inpstr[i - 1];
            char end = inpstr[i + 1];

            // Expand the short form and copy to the output string
            for (char c = strt + 1; c < end; ++c)
            {
                outstr[j++] = c;
            }
        }
        // Ignore non-alphabet characters

        i++;
    }

    // Null-terminate the output string
    outstr[j] = '\0';
}

int main()
{
    char inpstr[100], outstr[100];

    // Prompt the user to enter a short form string with alphabets
    printf("Enter small string with alphabets: ");
    scanf("%s", inpstr);

    // Call the expandAlphabets function
    expandAlphabets(inpstr, outstr);

    // Display the expanded string
    printf("Expanded string: %s", outstr);

    return 0;
}

