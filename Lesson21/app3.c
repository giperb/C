
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * allowedFlags[] = {"--version", "--help", "--who"};
const unsigned int lenght = sizeof allowedFlags / sizeof allowedFlags[0];

void validFlags(const char * array[], const unsigned int lenght)
{
    int incorrectFlag = -1;
    for (int i = 1; i < lenght; i++) {
        for (int j = 0; j < lenght; j++) {
            if (strcmp(array[i], allowedFlags[j]) == 0) {
                incorrectFlag = -1;
                break;
            }   else {
                incorrectFlag = i;
            }
        }
            if (incorrectFlag > -1) {
                printf("[-] %s Error flag.\n", array[i]);
                exit(EXIT_FAILURE);
            }

        }
    }

int main(const int argv, const char * argc[])
{
    if (argv > 1)
    validFlags(argc, argv);
        printf("\n[+] Congratulations!\n");
        
    return EXIT_SUCCESS;
}
