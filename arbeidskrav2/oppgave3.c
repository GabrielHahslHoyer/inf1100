#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void sjekk_tall(int start, int slutt, int faktor){
if (!(start <= faktor && faktor <= slutt)){     //checks if faktor is witin the range of start-slutt
    printf("that's not how numbers work dumbass\nthat was a bit rude \nI'm sorry \nthe factor has to be within the range of %d and %d\n", start, slutt);
    return;
}
//checks if the number is odd or even and a factor of 2
   if (faktor % 2 == 0 && faktor != 0){ 
    printf("%d is even and a factor of 2\n", faktor);
   }
   else if (faktor == 0){
    printf("%d is even and not a factor of 2, in fact it's not a factor of anything. because it's 0... and undefined...\n", faktor);
   }
   else {
    printf("%d is odd and not a factor of 2\n", faktor);
   }
}


int main (){
    sjekk_tall (-100,100,1100); //calls the sjekk_tall function
}