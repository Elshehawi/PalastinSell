#include <string.h>

#include "palestine_shell.h"

// 0: The strings are equal
// < 0: str1 < str2
// > 0: str1 > str2
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char *) str1 - *(unsigned char *) str2;
}

int my_strlen(const char *str) {
    size_t len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

int my_strncmp(const char *str1, const char *str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
    }
    return 0;
}
char *my_getenv(const char *name, char **env) {
    if (env == NULL || name == NULL)
        return NULL;

    size_t name_len = my_strlen(name);
    for (size_t i = 0; env[i]; i++) {
        // Check of the curr env var starts with 'name='
        if (my_strncmp(name, env[i], name_len) == 0 && env[i][name_len] == '=') {
            return &env[i][name_len + 1]; // Return the value part after 'name='
        }
    }
    return NULL; // Not found
}