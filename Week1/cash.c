#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define CENT_1 1
#define CENT_5 5
#define CENT_10 10
#define CENT_25 25

float get_Dollars(void);

int main(void) {

    int counter = 0;
    float dollars = get_Dollars();
    int cash = round(dollars * 100);

    while (cash > 0) {
        if (cash >= CENT_25) {
            cash -= CENT_25;
            counter++;
        }

        else if (cash >= CENT_10) {
            cash -= CENT_10;
            counter++;
        }

        else if (cash >= CENT_5) {
            cash -= CENT_5;
            counter++;
        }

        else if (cash >= CENT_1) {
            cash -=  CENT_1;
            counter++;
        }
    }
    printf("Iteration: %d\n",counter);
}


float get_Dollars(void) {
    float dollars;
    do {
        dollars = get_float("Enter the cash: \n");
    }

    while (dollars <= 0);
    return dollars;

}
