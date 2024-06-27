// Write a C program that returns index of first matched element from given array. if element is not found it returns -1. e.g., if array[] = {1, 2, 5, 9, 11} and search value entered is "5" than it returns 2. If search value entered is "7" which is not present inside array, so function returns -1.

#include <stdio.h>

int srch(int a[],int size,int elem){
    for(int i=0; i<size; i++){
        if(a[i]==elem){
            return i;
        }
    }
    return -1;
}

int main()
{

    int i = 0, size = 0, elem = 0, a[1000], y = 0, result;
    printf("Size of array: ");
    scanf("%d", &size);
    printf("Enter Numbers: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter  number to find: ");
    scanf("%d", &elem);

    result = srch(a, size, elem);

    printf("%d", result);

}

// -----------------------------------------------------------------

// int main()
// {
//     int i = 0, num = 0, find = 0, arr[1000];

//     // Prompt the user to enter the size of the array
//     printf("Size of array: ");
//     scanf("%d", &num);

//     if (num < 0)
//     {
//         printf("Negative array size is not allowed.\n");
//         return -1;
//     }

//     // Prompt the user to enter the elements of the array
//     printf("Enter Numbers: ");
//     for (i = 0; i < num; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     // Prompt the user to enter the number to find in the array
//     printf("Enter number to find: ");
//     scanf("%d", &find);

//     // Loop through the array to find the index of the given number
//     for (i = 0; i < num; i++)
//     {
//         if (arr[i] == find)
//         {
//             // Print the index and return it
//             printf("Index of %d: %d", find, i);
//             continue;
//         }
//         else
//         {
//             printf("-1");
//             return -1;
//         }
//     }

//     // If the number is not found, print -1 and return -1
// }

// --------------------------------------------------------------------------