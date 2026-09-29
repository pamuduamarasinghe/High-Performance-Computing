#include <stdio.h>
#include <math.h>


int main() {

    float u = 20;
    float theta = 30;
    float g = 9.81;

    float theta_rad = theta * M_PI / 180;

    float height = (u * u * sin(theta_rad) * sin(theta_rad)) / (2 * g);
	printf("Max height = %.4f m\n", height);
	
	float time = u * sin(theta_rad) / g ;
	printf("time to reach the max height = %.4f s\n", time);
	
	float total_time = time * 2;
	printf("total flight time = %.4f s\n", total_time);
	
	float distance = (u * cos(theta_rad) * total_time);
	printf("horizontal distance(Range) = %.4f m\n", distance );
	
	float final_velocity = -u * sin(theta_rad);
	printf("Final vertical velocity = %.4f m/s\n", final_velocity);

    return 0;
}