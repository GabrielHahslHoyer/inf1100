#include <stdio.h>
//makes triangle with the input of a character and amount of lines
void triangel(char tegn, int antall_linjer){
    
    int i = 1;  

if (antall_linjer <= 0){    //failsafe for input validity
        printf("invalid input \n");
        return;
}
else{   //making triangle
        while (i <= antall_linjer){ //uses i as a guiding variable that increases with increments of one as the code loops
            int x = 1;
            while (x <= i)  //prints characters until x == i 
            {
                printf("%c", tegn);
                x++;
            }
            printf ("\n");
            i++;
            
        }
    }

}

int main() {    //calls the function with input
    
    triangel('*', 6);
    return 0;
}