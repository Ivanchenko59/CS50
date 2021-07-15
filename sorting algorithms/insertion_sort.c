#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void insertion_sort(int arr[]);
void print_array(int arr[]);


int main(void) 
{
    int arr[N];
    srand(time(0));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion_sort(arr);
    print_array(arr);

    return 0;
}

void insertion_sort(int arr[]) 
{
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;   
    }

}

void print_array(int arr[]) 
{
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}