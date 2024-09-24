#include <stdio.h>

float average(int input[], int size){
    int i = 0;
    float sum = 0;
    float smallest = input[0];
    float largest = input[0];
    float averageof;
    //adds together all the elements of the array and checks for the largest and smallest elements
    while (i < size)
    {
        sum = sum + input[i];

        if (smallest > input[i]){
            smallest = input[i];
        }

        else if (largest < input[i]){
            largest = input[i];
        }
        
        i++;
    }
    averageof = (sum - smallest - largest) / (size - 2);    //takes the average minus the largest and smallest elements
    printf("%f %f %f\n", largest, smallest, sum);
    return averageof;
}

int main()
{
    int array[] = {2,5,7,8,9,7,6,6,8,89,6,4,3,4,5,6,78,543,5,453};
    int size = sizeof(array) / sizeof(array[0]);
    int i;
    float averageof = average(array, size);
    //printing for testing and checking results
    for (i = 0; i < size; i++){
        printf("%d \n", array[i]);
    }
    printf("%d \n", size);
    printf("%f \n", averageof);
    return 0;
}
