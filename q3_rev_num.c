// Write a C program to reverse the given number in most efficient way.

#include <stdio.h>

int main()
{
    int num, rev[10000], rem, i = 0; // Variables to store the input number, reversed number, and remainder

    // Prompt user to enter a number
    printf("Enter Number: ");
    scanf("%d", &num);

    if (num == 0)
    {
        printf("Enter number above 0...");
        return 0;
    }
    else
    {
        // Loop to reverse the given number
        while (num != 0)
        {
            rem = num % 10; // Get the last digit of the number
            rev[i] = rem;   // Build the reversed number
            num = num / 10; // Move to the next digit
            i++;
        }
    }

    // Display the reversed number
    printf("Rverse Number: ");
    for (int j = 0; j < i; j++)
    {
        printf("%d", rev[j]);
    }
}