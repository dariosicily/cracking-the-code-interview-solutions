#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool contains(const char *s, char c, size_t sz) 
{ 
    for (size_t i = 0; i < sz; ++i) {
            if (s[i] == c) {
                return true;
            }
    }
    return false;
}

/* remove all duplicate chars from a string*/
char* removeduplicate(char *s) 
{
    size_t nsinglechars = 0;

    for (size_t i = 0; s[i]; ++i) {
        char c = s[i];
        if (contains(s, c, nsinglechars) == false) {
            s[nsinglechars++] = c;           
        }
    }
    s[nsinglechars] = '\0';
    return s;
}

int main(void) 
{
    char s1[] = "aabbcad";
    char s2[] = "abcd";
    char s3[] = "abcdaaa";
    printf("%s\n", removeduplicate(s1));
    printf("%s\n", removeduplicate(s2));
    printf("%s\n", removeduplicate(s3));
    return 0;
}
