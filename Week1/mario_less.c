#include <cs50.h>
#include <stdio.h>

int get_Height(void);

int main(void)
{
    int Height = get_Height();
    
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Height-i-1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("#");
        }
    printf("\n");
  }

}

int get_Height(void) {
    int Height;
    do {
        Height = get_int("Enter the height: \n");
    }

    while (Height < 1 || Height > 8);
    return Height;

}
