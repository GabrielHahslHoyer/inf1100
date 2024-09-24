#include <stdio.h>

char letterOne = 'A';
char letterTwo = 'B';

//exchanges the values of letterOne and letterTwo
void changeLetters (char *letterOne, char *letterTwo){
    char temp;
    temp = *letterOne;
    *letterOne = *letterTwo;
    *letterTwo = temp;
}
//prints out the letters before and after being exchanges and calls the changeletter function
int main(){
    printf("%c is the original letter for the first argument\n", letterOne);
    printf("%c is the original letter for the second argument\n", letterTwo);
    changeLetters(&letterOne, &letterTwo);
    printf("%c is the new letter for the first argument\n", letterOne);
    printf("%c is the new letter for the second argument\n", letterTwo);
    return 0;
}