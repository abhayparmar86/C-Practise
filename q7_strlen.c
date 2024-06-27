#include <stdio.h>
int main()
{
   //Initializing variable.
    char str[100];
    int i,length=0;
    
     //Accepting input.
    printf("Enter a string: \n");
    gets(str);

     //Initializing for loop.
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i] != ' '){
            length++;
        }else{
            printf("Space Encountered at %d position, calculating length till space...", i+1);
            // return 0;
            break;
        }
         //Counting the length.
    }
    
    printf("\nLength of input string: %d",length);
    
     return 0;
}