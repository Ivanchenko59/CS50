#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    char text[256];

    if (argc != 2) {
        printf("Usage: %s key", argv[0]);
        exit(1);
    }

    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!(*(argv[1] + i) >= 48 && *(argv[1] + i) <= 57))  {
            printf("%c is not a digit", *(argv[1] + i));
            exit(2);
        }
    }

    const int key = atoi(argv[1]);

    printf("plaintext: ");

    fgets(text, sizeof(text), stdin);

    for (int i = 0; i < strlen(text); i++) {
        if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
            if (*(text + i) + key > 'Z') {
                *(text + i) = ((*(text + i) + key) -'A') % 26 + 'A';
            }
            else {
                *(text + i) += key;
            }
        }

        else if (*(text + i) >= 'a' && *(text + i) <= 'z') {
            if (*(text + i) + key > 'z') {
               *(text + i) = ((*(text + i) + key) -'a') % 26 + 'a';
            }
            else
            *(text + i) += key;
        }
    }

    printf("ciphertext: %s", text);
    return 0;
}
