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
		


	// Example 5
	printf("Example 5 \n");

	double P[] = {100,50,45,20,10};
	double R[] = {0.3 ,0.5,0.7,1.3,2.3};

	double V;
	for (int i = 0; i<5 ; i++){
		V= P[i] * R[i];
		V= sqrt(V);
		printf("%f,",V);

	}
	printf("\n");


	// Example 6
	printf("Example 6 \n");

	double I[] = {0.045,0.0225,0.0114,0.0096,0.0081};
	double r[] = {100 ,200,300,400,500};

	double p;
	for (int i = 0; i<5 ; i++){
		p = pow(I[i],2)*r[i];

		printf("%f, ",p);

	}
	printf("\n");


	return 0;
 }