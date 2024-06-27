// Write a C program to find 1's count in binary value of given integer number.

#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int num;   // Variable to store the input number
    int count = 0;      // Variable to store the count of 1's in the binary representation
    char binary[17];    // Array to store the binary representation of the input number

    // Prompt user to enter a number
    printf("Enter a Number: ");
    scanf("%u", &num); // Read the input number, %u is used for unsigned int

    // Convert the number to binary and store it in the binary array
    int i = 0;
    while (num > 0)
    {
        binary[i] = num % 2 + '0'; // Store the remainder (1 or 0) in the array
        if(binary[i]=='1'){
            count++; // Increment count if the remainder is 1 (binary digit is 1)
        }
        num = num / 2; // Divide the number by 2 to move to the next binary digit
        i++;
    }

    // Fill the remaining bits with '0'
    while(i < 4){
        binary[i] = '0'; // Append zeroes to the binary array until it has 16 digits
        i++;
    }
    
    binary[i] = '\0'; // Add null character to the end of the binary array

    // Display the binary representation of the input number in reverse order
    printf("Binary representation of number (in reverse order): ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", binary[j]);
    }
    printf("\n");

    // Display the count of 1's
    printf("Count of 1's in the binary representation: %d\n", count);

    return 0;
}
