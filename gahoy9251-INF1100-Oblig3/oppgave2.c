#include <stdio.h>
#include <stdbool.h>
//checks if the assignments meet the requirements to take the exam. Input is an array with 1's and 0's where 1 is accepted and the length of the array
bool ArbeidskravVerifikasjon (int arbeidskrav[], int size){
    int REQUIREDAMOUNT = 4;
    int acceptedAssignments = 0;
    bool requiredAssignments = false;
        int i = 0;
    
    while (i < size)    //counts the amount of accepted assignments
    {
        if (arbeidskrav[i] != 0){
            acceptedAssignments++;
        }
        i++;    
    }
    //checks if the required assignments are accepted
    if (arbeidskrav[2] != 0 || arbeidskrav[5] != 0)
    {
        requiredAssignments = true;
    }
    //checks if the student can take the exam and returns a bool
    if (acceptedAssignments >= REQUIREDAMOUNT && requiredAssignments == true ){
        return true;
    }
    else {
        return false;
    }
    
}

int main() {
    int arbeidskrav[] = {1, 1, 1, 1, 1, 0};
    int size = sizeof(arbeidskrav) / sizeof(arbeidskrav[0]);
    bool result = ArbeidskravVerifikasjon(arbeidskrav, size);
    printf("%s\n", result ? "true":"false");
    return 0;
}