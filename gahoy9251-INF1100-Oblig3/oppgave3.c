#include <stdio.h>
#include <string.h>

char newString[100];

void reversal (char input[]){
        int i = 0;
        int length = strlen(input) - 1; 
        //reverses the input string and saves it in a new array
        while (length >= 0)             
        {
            newString[i] = input[length];
            i++;
            length--;
        }
        newString[i] = '\0';    //required to make the string valid
}

int main()
{
    char input[] = "This is my string, I like it quite a lot actually";
    reversal(input);
    printf("%s \n", newString);
    return 0;
}
