#include <stdio.h>
#include <math.h>

// Avstanden mellom to punkt i planet, hvor (𝑥1, 𝑦1) er punkt 1 og (𝑥2, 𝑦2) er punkt to er definert som:
// √(𝑥1 − 𝑥2)2 + (𝑦1 − 𝑦2)2
// Lag en funksjon som kalkulerer avstanden mellom to punkt i planet

void distance (double x1, double x2, double y1, double y2){
    double xExponent = pow((x1 - x2), 2);
    double yExponent = pow((y1 - y2), 2);
    printf("The distance between the two points given is %lf\n", sqrt(xExponent + yExponent));
}

int main(){
    distance (2,3,2,23);
    return 0;
}