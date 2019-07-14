#include <stdio.h>
#include <string.h>

/* a simple function which reverses chars in a string*/
char *reverse(char *s) 
{
    size_t length = strlen(s), half = length / 2;

    /*swap elements inside s*/
    for (size_t i = 0; i < half; ++i) {
        char tmp = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = tmp;
    }
    return s;
}


int main() 
{
    char s1[] = "abcd";
    char s2[] = "abc";
    printf("%s\n", reverse(s1));
    printf("%s\n", reverse(s2));
    return 0;
}
