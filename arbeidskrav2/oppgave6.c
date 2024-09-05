#include <stdio.h>

int sumOfArray (int myNumber){
    int sum = 0; //variable to save the sum of the digits of myNumber
    
    while (myNumber > 0){   //separating the digits myNumber contains and adding them together in the sum variable
        int modulo = myNumber % 10;
        sum = sum + modulo;
        myNumber = myNumber / 10;
    }
    printf("%d\n ", sum);   //printing the result for insight
    return sum;
}

int main (){
    int myNumber = 999999999; //the number used for the function call to sumOfArray (I originally planned to save the split up number in an array and add them together in a separate function)
    int sum = sumOfArray(myNumber);

    while (sum > 10)   //calls the sumofArray function until the sum only contains one digit
        sum = sumOfArray(sum);
    
    return 0;
}