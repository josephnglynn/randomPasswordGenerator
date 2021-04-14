#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int lengthOfPassword = 16;

int main(int argc, char *argv[]) {

    for (unsigned int i = 0; i < argc; i++) {
        if (argv[i] == NULL) {
            break;
        }

        if (strcmp(argv[i], "-length") == 0 || strcmp(argv[i], "-l") == 0) {
            i++;
            lengthOfPassword = atoi(argv[i]);
        }

        if (strcmp(argv[i], "-help") == 0 || strcmp(argv[i], "-h") == 0) {
            printf("-length / -l : takes number following flag and produces password with that length");
        }
    }

    srand(time(NULL));

    char password[lengthOfPassword];

    for (unsigned int i = 0; i < lengthOfPassword; i++) {
        password[i] =  (char) (rand() % 94 + 33);
    }

    printf("GENERATED PASSWORD IS: %s\n", password);
}