#include <stdio.h>
#include <time.h>

void num_to_string(int num)
{

    if (num < 0)
    {
        printf("Negative Number is Not allowed, making it positive...");
        num = -num;
        // return num;
    }

    char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int tensPart = (num % 100) / 10;
    int unitsPart = num % 10;

    if (num >= 100000)
    {
        num_to_string(num / 100000);
        printf("Lakh ");
        num %= 100000;
    }

    if (num >= 1000)
    {
        num_to_string(num / 1000);
        printf("Thousand ");
        num %= 1000;
    }

    // Print hundreds place
    if (num >= 100)
    {
        num_to_string(num / 100);
        printf("Hundred ");
        num %= 100;
    }

    // Print tens and units place
    if (tensPart == 1)
    {
        // If the number is in the teens
        if (unitsPart > 0)
        {
            printf("%s ", teens[unitsPart]);
        }
        else
        {
            printf("%s ", tens[tensPart]);
        }
    }
    else
    {
        // If the number is not in the teens
        if (tensPart > 0)
        {
            printf("%s ", tens[tensPart]);
        }
        if (unitsPart > 0)
        {
            printf("%s ", units[unitsPart]);
        }
    }

    // printf("\n");
}

int main()
{
    clock_t start_time = clock();
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    num_to_string(num);

    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time taken to convert: %f seconds", time_taken);
    return 0;

    return 0;
}

// -----------------------------------------------------------------------

// void convert(int num)
// {
//     // if (num < 0)
//     // {
//     //     printf("Negative Number");
//     //     num = -num;
//     // }

//     if (num == 0)
//     {
//         printf("zero");
//         return;
//     }

//     if(num >= 100000)
//     {
//         convert(num / 100000);
//         printf(" lakhs ");
//         num %= 100000;
//     }

//     if (num >= 1000)
//     {
//         convert(num / 1000);
//         printf(" thousand ");
//         num %= 1000;
//     }

//     if (num >= 100)
//     {
//         convert(num / 100);
//         printf(" hundred ");
//         num %= 100;
//     }

//     if (num >= 20)
//     {
//         switch (num / 10)
//         {
//         case 2:
//             printf("twenty ");
//             break;
//         case 3:
//             printf("thirty ");
//             break;
//         case 4:
//             printf("forty ");
//             break;
//         case 5:
//             printf("fifty ");
//             break;
//         case 6:
//             printf("sixty ");
//             break;
//         case 7:
//             printf("seventy ");
//             break;
//         case 8:
//             printf("eighty ");
//             break;
//         case 9:
//             printf("ninety ");
//             break;
//         }
//         num %= 10;
//     }

//     if(num >= 10){
//         int k = num % 10;
//         switch (k)
//         {
//         case 0:
//             printf("ten");
//             break;

//         case 1:
//             printf("eleven");
//             break;

//         case 2:
//             printf("twelve");
//             break;

//         case 3:
//             printf("thirteen");
//             break;

//         case 4:
//             printf("fourteen");
//             break;

//         case 5:
//             printf("fifteen");
//             break;

//         case 6:
//             printf("sixteen");
//             break;

//         case 7:
//             printf("seventeen");
//             break;

//         case 8:
//             printf("eightteen");
//             break;

//         case 9:
//             printf("nineteen");
//             break;
//         }
//     }

//     if (num >= 1)
//     {
//         switch (num)
//         {
//         case 1:
//             printf("one");
//             break;
//         case 2:
//             printf("two");
//             break;
//         case 3:
//             printf("three");
//             break;
//         case 4:
//             printf("four");
//             break;
//         case 5:
//             printf("five");
//             break;
//         case 6:
//             printf("six");
//             break;
//         case 7:
//             printf("seven");
//             break;
//         case 8:
//             printf("eight");
//             break;
//         case 9:
//             printf("nine");
//             break;
//         }
//     }
// }

// int main()
// {

//     clock_t start_time = clock();
//     int num;
//     printf("Enter the Number: ");
//     scanf("%d", &num);
//     printf("%d = ", num);
//     convert(num);
//     clock_t end_time = clock();

//     double time_taken = ((double)(end_time - start_time))/CLOCKS_PER_SEC;
//     printf("\n");
//     printf("Time taken to convert: %f seconds", time_taken);
//     return 0;
// }