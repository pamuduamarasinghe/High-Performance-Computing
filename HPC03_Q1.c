#include <stdio.h>




int main(){
    int num1 = 8;
    printf("The value of num is: %d\n", num1);
    printf("The address of num is: %p\n", &num1);
    
    //1 Memeory Allocation
    float num2 = 10.0;
    printf("The value of num is: %f\n", num2);
    printf("The address of num is: %p\n", &num2);
   
   //2 Pointers
    int *ptr1;
    ptr1 = &num1;
    printf("The value of num1 variable is: %d\n", *ptr1);
    printf("The address of num1 variable is: %p\n", ptr1);

    int *ptr2;
    ptr2 = &num2;
    printf("The value of num2 variable is: %f\n", *ptr2);
    printf("The address of num2 variable is: %p\n", ptr2);

    return 0;
}
