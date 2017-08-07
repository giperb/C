#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define AC_RED     "\x1b[31;1m"
#define AC_GREEN   "\x1b[32;40m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"

#define APP_VERSION "0.1.0"

void versionCommand(void);
void helpCommand(void);

const char * const allowedFlags[] = { "--version", "--help" };

const unsigned int allowedFlagsLength = sizeof allowedFlags / sizeof allowedFlags[0];
void(*commandStore[])(void) = {versionCommand, helpCommand};
void validateFlags(const char * const flags[], const int length)

{
    int incorrectFlagIndex = -1;
    
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < allowedFlagsLength; j++)
        {
            if (strcmp(flags[i], allowedFlags[j]) == 0)
            {
                incorrectFlagIndex = -1;
                break;
            }
            else incorrectFlagIndex = i;
        }
        if (incorrectFlagIndex > -1)
        {
            printf(AC_RED "[-] Error: %s incorrect flag was given!%s\n", flags[incorrectFlagIndex], AC_RESET);
            exit(EXIT_FAILURE);
        }
    }
}

void invokeCommands(const char * const commands[], const unsigned int count)
{
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < allowedFlagsLength; j++) {
            if (strcmp(commands[i], allowedFlags[j]) == 0) {
                commandStore[j]();
            }
        }
    }
}
void versionCommand(void)
{
    printf("App is version: %s\n", APP_VERSION);
}
void helpCommand(void)
{
    printf("Help command invoked.\n");
}

int main(const int argc, const char * const argv[])
{
    if (argc > 1) validateFlags(argv, argc);
    
    else printf(AC_GREEN "[+] Congratulations!%s\n", AC_RESET);
    
    invokeCommands(argv, argc);
    
    
    return EXIT_SUCCESS;
}
