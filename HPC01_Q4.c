#include <stdio.h>
#include <math.h>

float pair_euclidean_distance(int x[], int y[], int z[], int i){
    int dx = x[i] - x[i + 1];
    int dy = y[i] - y[i + 1];
    int dz = z[i] - z[i + 1];

    return sqrtf(dx * dx + dy * dy + dz * dz);
}

int main()
{
    int x[] = {1, -6, 1, -4, 8, 6};
    int y[] = {10, -5, 3, 1, 1, 3};
    int z[] = {6, 3, 28, -8, 1, 4};

    int n = sizeof(x) / sizeof(x[0]);

    float min_distance = pair_euclidean_distance(x, y, z, 0);
    int min_index = 0;

    printf("Pairwise distances:\n");

    for (int i = 0; i < n - 1; i++){
        float distance = pair_euclidean_distance(x, y, z, i);

        printf("Distance between point %d and point %d = %.4f\n",i, i + 1, distance);

        if (distance < min_distance)
        {
            min_distance = distance;
            min_index = i;
        }
    }

    printf("\nMinimum distance = %.4f\n", min_distance);
    printf("Index of minimum distance = %d\n", min_index);

    printf("Pair with minimum distance:\n");

    printf("Point %d = (%d, %d, %d)\n",min_index,x[min_index],y[min_index],z[min_index]);

    printf("Point %d = (%d, %d, %d)\n",min_index + 1,x[min_index + 1],y[min_index + 1],z[min_index + 1]);

    return 0;
}