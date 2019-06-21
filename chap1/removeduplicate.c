#include <stdio.h>
#include <string.h>

/* remove all dup chars from a string*/
char* removeduplicate(char *s) {
    size_t length = strlen(s), i , j, index = 0;
    int duplicate;

    for (i = 0; i < length; ++i) {

        /*check if the s[i] char is a duplicate*/
        duplicate = 0;
        for (j = 0; j < index; ++j) {
            if (s[i] == s[j]) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) s[index++] = s[i];
    }
    s[index] = '\0';
    return s;
}

int main() {
    char s1[] = "aabbcad";
    char s2[] = "abcd";
    char s3[] = "abcdaaa";
    printf("%s\n", removeduplicate(s1));
    printf("%s\n", removeduplicate(s2));
    printf("%s\n", removeduplicate(s3));
    return 0;
}
