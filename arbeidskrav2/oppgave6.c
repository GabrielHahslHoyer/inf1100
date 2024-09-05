#include <stdio.h>

int sumOfArray (int myNumber){
    int sum = 0;
    
    while (myNumber > 0){
        int modulo = myNumber % 10;
        sum = sum + modulo;
        myNumber = myNumber / 10;
    }
    printf("%d\n ", sum);
    return sum;
}

int main (){
    int myNumber = 999999999;
    int sum = sumOfArray(myNumber);

    if (sum >= 10){
        sumOfArray(sum);
    }
    return 0;
}