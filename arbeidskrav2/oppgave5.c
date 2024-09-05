#include <stdio.h>

float main (){
    float kilograms;
    int unit;
    float centner = 0.01;
    float newton = 9.8;
    float karat = 5000;

    printf("Hello, this program is made to convert between different units of measurment\n");
    printf("the only valid input unit for this program is kilograms\n");
    printf("how many kilograms would you like to convert?\n");
    scanf("%f", &kilograms);
    printf("what do you want to convert to? 1 for Centner, 2 for Newton and 3 for Karat\n");
    scanf("%d", &unit);
    switch (unit)
    {
    case (1):
        printf("%f converted to centner is : %f \n", kilograms, kilograms * centner);
        break;

    case (2):
        printf("%f converted to newton is : %f\n",kilograms, kilograms * newton);
        break;

    case (3):
        printf("%f converted to karat is : %f \n",kilograms, kilograms * karat);
        break;
    
    default:
        printf("You're not very good at following instructions are you?\n");
        break;
    }
}