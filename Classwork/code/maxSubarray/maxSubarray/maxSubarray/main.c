
#include <stdio.h>
#include <limits.h>

void naiveMaxSubarray(int arr[], int n, int *i_max, int *j_max)
{
    int currentMax = arr[0];
    *i_max = *j_max = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum > currentMax)
            {
                currentMax = sum;
                *i_max = i;
                *j_max = j;
            }
        }
    }
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i_max, j_max;
    
    naiveMaxSubarray(arr, n, &i_max, &j_max);
    
    printf("The maximum subarray is [%d, %d]\n", i_max, j_max);
    
    return 0;
}
