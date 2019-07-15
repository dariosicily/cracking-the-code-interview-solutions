#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* check if the string contains only unique chars using an auxiliary 
 * buffer to store frequencies*/
bool has_unique(const char *s) 
{
    int alphabet[26] = { 0 };
    size_t i = 0;

    /*store the frequencies of the chars of the string*/
    while (s[i]) {
        size_t index = s[i] - 'a';
        ++alphabet[index];
        ++i;
    }

    /* check if all elements of alphabet have frequency equal to 1 or 0*/
    for (i = 0; i < 26; ++i)
        if (alphabet[i] > 1) return false;
    return true;
}

/* check if the string contains only unique chars without using buffer*/
bool has_unique_brute_force(const char *s) 
{
    size_t l = strlen(s);

    /*use of brute force avoiding comparison with previous elements*/
    for (size_t i = 0; i < l - 1; ++i)
        for (size_t j = i + 1; j < l; ++j)
            if (s[i] == s[j]) return false;
    return true;
}

int main(void) 
{
    printf("%d\n", has_unique("abcd"));
    printf("%d\n", has_unique_brute_force("abcd"));
    printf("%d\n", has_unique("abcda"));
    printf("%d\n", has_unique_brute_force("abcda"));
    return 0;
}
