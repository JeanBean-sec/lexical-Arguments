// welcome to LexicalArguments!

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main();

int main()
{
    char input[100] = "";

    // while(true){
    //     printf(">> ");
    //     fflush(stdout);

    //     if (fgets(input, sizeof(input), stdin) == NULL) break;

    //     input[strcspn(input, "\n")] = '\0';

    //     if (strcmp(input, "exit") == 0){
    //         break;
    //     }
    // }

    while (1)
    {

        printf("T_T: ");

        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "\n") == 0)
        {
            continue;
        }
        else if (strcmp(input, "\n") == 1)
        {
            if (strcmp(input, "exit\n") == 0 ||
                     strcmp(input, "quit\n") == 0)
            {
                printf("Goodbye!");
                break;
            }

            else if (strcmp(input, "help\n") == 0)
            {
                printf("exit - gets you out.\n");
                printf("quit - gets you out.\n");
                continue;
            }
            else{
                printf("No. enter 'help' if you're confused.\n");
            }
            continue;
        }
    }
    return 0;
}