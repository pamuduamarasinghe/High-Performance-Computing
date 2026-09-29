#include <stdio.h>
#include <math.h>

int main(int argc,const char * arg[]){
	
	printf("Question  2 \n");
	float Y[] = {12.5,14.6,18.4,12.7,14.8,16.8,17.4,10.3,11.1,17.3,9.3,16.4,15.2,14.7};
	int n =14;

	//Mean
	float mean = 0.0;


	for(int i; i < n;i++ ){
		mean = mean + Y[i];

	}

	mean = mean /n;
	
	printf("Mean of data  = %f \n",mean);
	printf("\n");

	//median
	float median;
	//sorting
	
	
	for(int i; i < n;i++ ){
		if(Y[i]< Y[i+1]);
			float temp = Y[i];
			Y[i] = Y[i+1];
			Y[i+1]=temp;


	}

	if (n %2 == 0){
		median = (Y[n/2 -1]+ Y[n/2])/ 2 ;

	}
	else {
		median = Y[n/2];
	}

	
	printf("Median of data  = %f \n",median);
	printf("\n");

	// Std deviation
	float var =0.0 ;

	for(int i; i < n;i++ ){
		var = var + (Y[i]- mean)*(Y[i]- mean);

	}

	var = var /n;
	
	printf("variance of data  = %f \n",var);
	printf("Std Deviasion of data  = %f \n",sqrt(var));
	printf("\n");

	// Y was sorted 
	printf("Max of data  = %f \n",Y[1]);
	printf("Min of data  = %f \n",Y[n]);

	return 0;
 }