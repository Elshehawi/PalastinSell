#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "palestine_shell.h"


// cd, cd [path], cd - (previos directory), cd ~ (home directory), handle non existing directories, permission issues
int command_cd(char **args, char *init_dir) {
    (void) init_dir;
    if (args[1] == NULL) {
        printf("cd: expected argument \"cd [dir]\"\n");
    } else if (chdir(args[1]) == 0) {
        // printf("cd worked\n");
    } else {
        perror("cd");
    }
    return 0;
}

int command_pwd() {
    char *cwd = NULL;

    // use dynamic allocation to avoid buffer overflow
    cwd = getcwd(NULL, 0);
    if (cwd != NULL) {
        printf("%s\n", cwd);
        free(cwd);
    } else {
        perror("getcwd");
    }
    return 0;
}


int command_echo(char **args, char **env) {
    int new_line = 1; // By default, echo adds a newline at the end
    int start_index = 1; // Start printing from the first argument

    if (args[1] != NULL && my_strcmp(args[1], "-n") == 0) {
        new_line = 0; // If -n is provided, do not add a newline
        start_index++; // Start printing from the second argument
    }

    // Process remaining arguments
    for (; args[start_index]; start_index++) {
        if (args[start_index][0] == '$') // handle env vars
        {
            char *value = my_getenv(args[start_index] + 1, env);
            if (value) {
                printf("%s", value);
            } else {
                printf(" ");
            }
        } else {
            printf("%s", args[start_index]);
        }
        if (args[start_index + 1] != NULL) {
            new_line = 0;
            printf(" "); // Print space between arguments
        }

        if (new_line) {
            printf("\n");
        }
        new_line = 1; // Reset for next argument
    }
    return 0;
}

int command_env(char** env)
{
    size_t index = 0;
    while (env[index])
    {
        printf("%s\n", env[index]);
        index++;
    }
    return 0;
}
int command_which(char **args, char **env);
