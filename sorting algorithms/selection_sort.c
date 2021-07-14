#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void) 
{
    int arr[N];
    srand(time(0));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < N - 1; i++) {
        int k = i;
        int tmp = arr[i];
        for (int j = i+1; j < N; j++) {
            if (arr[j] < tmp) {
                tmp = arr[j];
                k = j;
            }
        }
    arr[k] = arr[i];
    arr[i] = tmp;
    printf("%d ", arr[i]);
    }

    return 0;
}
