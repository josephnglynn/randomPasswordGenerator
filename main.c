#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//DEFAULT VALUES
int lengthOfPassword = 16;
int numbersAndLetters = 0;


static void usage() {
    printf(
            "   -length / -l : takes number following flag and produces password with that length\n"
            "   -numbersAndLetters / -nl : only outputs a password containing numbers and letters\n"
            "   -help / -h : outputs help"
            );
}

int main(int argc, char *argv[]) {

    for (unsigned int i = 0; i < argc; i++) {
        if (argv[i] == NULL) {
            break;
        }

        if (strcmp(argv[i], "-length") == 0 || strcmp(argv[i], "-l") == 0) {
            i++;
            lengthOfPassword = atoi(argv[i]);
        }

        if (strcmp(argv[i], "-nl") == 0 || strcmp(argv[i], "-numbersAndLetters")) {
            numbersAndLetters = 1;
        }

        if (strcmp(argv[i], "-help") == 0 || strcmp(argv[i], "-h") == 0) {
            usage();
        }
    }

    srand(time(NULL));

    char password[lengthOfPassword];

    if (numbersAndLetters) {
        for (unsigned int i = 0; i < lengthOfPassword; i++) {
            password[i] = rand() % 75 + 48;
            while ((password[i] > 57 && 65 > password[i]) || (password[i] > 90 && password[i] < 97) ) {
                password[i] = rand() % 75 + 48;
            }
        }
    } else {
        for (unsigned int i = 0; i < lengthOfPassword; i++) {
            password[i] =  (char) (rand() % 94 + 33);
        }
    }

    printf("GENERATED PASSWORD IS: %s\n", password);
}