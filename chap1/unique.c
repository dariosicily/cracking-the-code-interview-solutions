#include <stdio.h>
#include <string.h>

int has_unique(const char *s) {
    int index;
    int alphabet[26] = { 0 };
    int i = 0;

    /*store the frequencies of the chars of the string*/
    while (s[i]) {
        index = s[i] - 'a';
        ++alphabet[index];
        ++i;
    }

    /* check if all elements of alphabet have frequency equal to 1 or 0*/
    for (i = 0; i < 26; ++i)
        if (alphabet[i] > 1) return 0;
    return 1;
}

int has_unique_brute_force(const char *s) {
    size_t i, j, l = strlen(s);

    /*use of brute force avoiding comparison with previous elements*/
    for (i = 0; i < l - 1; ++i)
        for (j = i + 1; j < l; ++j)
            if (s[i] == s[j]) return 0;
    return 1;
}

int main() {
    printf("%d\n", has_unique("abcd"));
    printf("%d\n", has_unique_brute_force("abcd"));
    printf("%d\n", has_unique("abcda"));
    printf("%d\n", has_unique_brute_force("abcda"));
    return 0;
}
