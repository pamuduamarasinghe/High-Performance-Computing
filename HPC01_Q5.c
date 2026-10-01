#include <stdio.h>
#include <math.h>

int main(){

    printf("Input Positive integer\n");
    int n;

    if (scanf("%d",&n) != 1) {
        printf("Invalid input. Please enter a positive integer.\n");
    }
    else if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
    }
    else{
        // n is prime
        if (n <= 1) {
            printf("%d is not a prime number.\n", n);
        } else {
            int is_prime = 1; // Assume n is prime

            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    is_prime = 0; // n is not prime
                    break;
                }
            }

            if (is_prime) {
                printf("%d is a prime number.\n", n);
            } else {
                printf("%d is not a prime number.\n", n);
            }
        }
    }

    return 0;
}