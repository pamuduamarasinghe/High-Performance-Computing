#include <stdio.h>




int main(){
    int num1 = 8;
    printf("The value of num is: %d\n", num1);
    printf("The address of num is: %p\n", &num1);
    
    //1 Memeory Allocation
    float num2 = 10.0;
    printf("The value of num is: %f\n", num2);
    printf("The address of num is: %p\n", &num2);

    printf("\n");
   
   //2 Pointers
    int *ptr1;
    ptr1 = &num1;
    printf("The value of num1 variable is: %d\n", *ptr1);
    printf("The address of num1 variable is: %p\n", ptr1);

    int *ptr2;
    ptr2 = &num2;
    printf("The value of num2 variable is: %f\n", *ptr2);
    printf("The address of num2 variable is: %p\n", ptr2);

    printf("\n");

    //3 Print messages using pointers
    char text[] = "How are you doing friends";
    char *pt;
    pt = text;

    for (int i=0 ; i<25; i++){
        printf("%c", *pt);
        pt++;
    }
    printf("\n");


    char text1[] = "We will watch a movie tonight.Hope everyone will be there";
    char *pt1;
    pt1 = text1;

    for (int i=0 ; i<25; i++){
        printf("%c", *pt1);
        pt1++;
    }
    printf("\n");


    // Print numbers using pointers in reverse order

    int numbers[] = {1, 2, 3, 4, 5};
    int *pt_num = numbers;

    for (int i=5 ; i>0; i--){
        printf("%d ", *pt_num);
        pt_num++;
    }
    printf("\n");

    return 0;
}
