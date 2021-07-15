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
    printf("Success key %d", key);
    printf("\nplaintext: ");
    scanf("%s", text);

    for (int i = 0; i < strlen(text); i++) {
         if (*(text + i) != ',' && *(text + i) != ' ') {    
            *(text + i) += key;
            if (*(text + i) > 'z') {
                *(text + i) = *(text + i) % 'z' + 'a' - 1;
            }
        }
    }

    printf("\nciphertext: %s", text);
    return 0;
}
