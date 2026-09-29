#include <stdio.h>
#include <math.h>

int main(int argc,const char * arg[]){
	
	//Example 3
	printf("Example 3 \n");
	float Ytrue[] = {6.0000,6.5000,7.0000,7.5000,8.0000,8.5000,9.5000};
	float Yexp[] = {6.4935,6.9935,7.4935,7.9935,8.4935,8.9935,9.4935,9.9935};
	
	float mae =0.0;
	for(int i=0; i < 8 ; i++){
		mae = mae +fabs(Ytrue[i] - Yexp[i]);
		
	}
	
	mae = mae/8;
	printf("MAE = %f \n",mae);


	
	//Example 4

	printf("Example 4 \n");
	int arr[] = {1,2,3,4,5,6,7,8,9};

	for (int i = 0; i< 9 ; i++){
		int a = arr[i] ;
		if (fmod(a,2)==1){
			arr[i] = a + 1;

		}

	}
	
	
	printf("New array is \n");

	for (int i = 0; i< 9 ; i++){
	
		printf("%d ",arr[i]);
		}

		printf("\n");
		return 0;


	// Example 5
	printf("Example 5 \n");

	double P[] = {};

 }