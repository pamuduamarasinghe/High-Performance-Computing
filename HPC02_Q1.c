#include <stdio.h>
#include <math.h>


int Int_sum(int n){
    return n*(n+1)/2;
}

int Factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * Factorial(n - 1);
    }
}   

int main(){


    // Integer sum
    printf("Input integer to get the sum of first n integers: ");
    int n;
    scanf("%d", &n);
    int sum = Int_sum(n);

    printf("Sum of first %d integers is: %d\n", n, sum);


    // Factorial Calculation
    printf("Input integer to get the factorial: ");
    int m;
    scanf("%d", &m);

    printf("Factorial of %d is: %d\n", m, Factorial(m));



   

    return 0;
}