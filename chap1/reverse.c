#include <stdio.h>
#include <string.h>

char *reverse(char *s) {
    size_t length = strlen(s), half = length / 2, i;
    char tmp;

    /*swap elements */
    for (i = 0; i < half; ++i) {
        tmp = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = tmp;
    }
    return s;
}


int main() {
    char s1[] = "abcd";
    char s2[] = "abc";
    printf("%s\n", reverse(s1));
    printf("%s\n", reverse(s2));
    return 0;
}
