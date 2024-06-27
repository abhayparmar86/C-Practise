// Write a C function to invert the bits in given integer variable. The inversion of bits should start from given position and should be done up to given counts.

#include <stdio.h>

int invert(int a, int strt, int end);

int main()
{
    int num = 0, strt = 0, end = 0;

    // Prompt user to enter an integer
    printf("Enter Integer Value:");
    scanf("%d", &num);

    int temp = num;
    int binary[100], i = 0;
    while (temp > 0)
    {
        binary[i] = temp % 2; // Store the remainder (1 or 0) in the array
        temp = temp / 2;      // Divide the number by 2 to move to the next binary digit
        i++;
    }

    // Display the binary representation of the input number
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }

    // Prompt user to enter the starting position (under 32)
    printf("\nEnter Starting Position:");
    scanf("%d", &strt);

    // Prompt user to enter the ending position (under 32)
    printf("Enter ending Position:");
    scanf("%d", &end);

    // Call the invert function
    invert(num, strt, end);

    return 0;
}

// Defining the invert function
int invert(int a, int strt, int end)
{
    // Loop through the specified bit positions and invert each bit
    for (int i = (strt - 1); i < end; i++)
    {
        a = (1 << i) ^ a; // Invert the i-th bit using XOR (^)
    }

    // Display the result
    printf("%d\n", a);

    int rev_binary[100], i = 0;
    while (a > 0)
    {
        rev_binary[i] = a % 2; // Store the remainder (1 or 0) in the array
        a = a / 2;             // Divide the number by 2 to move to the next binary digit
        i++;
    }

    // Display the binary representation of the input number
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", rev_binary[i]);
    }

    return a; // Return the inverted value
}