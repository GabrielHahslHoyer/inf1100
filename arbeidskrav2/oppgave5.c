#include <stdio.h>

float main (){
    float kilograms;    //variable for user input measured in kilograms
    int unit;   //variable for user input for which type of unit they want. 1 for centner, 2 for newton, 3 for karat
    float CONVERSIONFACTOR_CENTNER = 0.01;  //constant for centner
    float CONVERSIONFACTOR_NEWTON = 9.8;    //constant for newton
    float CONVERSIONFACTOR_KARAT = 5000;    //constant for karat

    printf("Hello, this program is made to convert between different units of measurment\n");
    printf("the only valid input unit for this program is kilograms\n");
    printf("how many kilograms would you like to convert?\n");
    scanf("%f", &kilograms);    //asks user for input in kilograms 
    printf("what do you want to convert to? 1 for Centner, 2 for Newton and 3 for Karat\n");
    scanf("%d", &unit); //asks user for input for what type of unit they want the conversion to result in
    switch (unit)   //switch for the different conversions the program allows, also does the conversion math
    {
    case (1):
        printf("%f converted to centner is : %f \n", kilograms, kilograms * CONVERSIONFACTOR_CENTNER);
        break;

    case (2):
        printf("%f converted to newton is : %f\n",kilograms, kilograms * CONVERSIONFACTOR_NEWTON);
        break;

    case (3):
        printf("%f converted to karat is : %f \n",kilograms, kilograms * CONVERSIONFACTOR_KARAT);
        break;
    
    default:
        printf("You're not very good at following instructions are you?\n");
        break;
    }
}