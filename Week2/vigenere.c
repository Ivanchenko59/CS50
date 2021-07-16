#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main (int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./vigenere keyword");
        exit(1);
    }
    
    char text[256];
    int key_len = strlen(argv[1]);
    int j = 0;


    for (int i = 0; i < strlen(argv[1]); i++) {
        if (*(argv[1] + i) >= '0' && *(argv[1] + i) <= '9')  {
            printf("%c is not a keyword", *(argv[1] + i));
            exit(1);
        }
    }

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; i < strlen(text) - 1; i++) {                                    //-1????
        if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
            if (*(text + i) + shift(argv[1][j]) > 'Z') {
                *(text + i) = ((*(text + i) + shift(argv[1][j])) -'A') % 26 + 'A';
            }
            else {
                *(text + i) += shift(argv[1][j]);
            }
        }

        else if (*(text + i) >= 'a' && *(text + i) <= 'z') {
            if (*(text + i) + shift(argv[1][j]) > 'z') {
               *(text + i) = ((*(text + i) + shift(argv[1][j])) -'a') % 26 + 'a';
            }
            else
            *(text + i) += shift(argv[1][j]);
        }

        if (!(*(text + i) >= 32 && *(text + i) <= 47)) {
            j++;
        }
        if (j == key_len) {
            j = 0;
        }
    }

    printf("ciphertext: %s", text);
    return 0;
}


int shift(char c) {

    if (isupper(c)) {
        return c -'A';
    }
    else {
        return c - 'a';
    }
}