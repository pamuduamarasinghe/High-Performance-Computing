#include <stdio.h>
#include <math.h>


float Int_sum(int x){
    return x*(x+1)/2;
}


int main(){

    // f(x) = x^3 + 10x + 1    for [0,2]

    printf("f(x) = x^3 + 10x + 1    for [0,2]\n");


    float analytical_area = 26.0;
    printf("Analytical Area: %.2f\n", analytical_area);

    float a = 0.0;  // lower limit
    float b = 2.0;  // upper limit
    int n = 100;  // sub interval

    float trapezoidal_area = trapezoidal_rule(a, b, n);
    printf("Trapezoidal Area: %.2f\n", trapezoidal_area);

    float simpsons_area = simpsons_rule(a, b, n);
    printf("Simpson's Area: %.2f\n", simpsons_area);

    float error_trape = fabs(analytical_area - trapezoidal_area);
    float error_simp = fabs(analytical_area - simpsons_area);

    printf("Error (Trapezoidal): %.2f\n", error_trape);
    printf("Error (Simpson's): %.2f\n", error_simp);

    return 0;
}