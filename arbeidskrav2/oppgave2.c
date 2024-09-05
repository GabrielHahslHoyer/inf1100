#include <stdio.h>

void changeCapitalization (char letter){

int ascii = letter;

if (ascii <= 90 && ascii >= 65){
    char lowerCase = ascii + 32;
    printf("The lowercase version of the letter is: %c\n", lowerCase);
}

else if (ascii >= 97 && ascii <= 122){
    char upperCase = ascii - 32;
    printf("The uppercase version of the letter is: %c\n", upperCase);
}
else {
    printf("The input is not a letter in the english alphabet \n");
}
}

int main (){
    changeCapitalization ('Q');
    changeCapitalization ('w');
    changeCapitalization ('F');
    changeCapitalization ('p');
    changeCapitalization ('G');
    changeCapitalization ('j');
    changeCapitalization ('6');
    changeCapitalization ('7');
    return 0;
}