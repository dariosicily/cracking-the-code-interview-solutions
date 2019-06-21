#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* check if str1 can be obtained from string2 adding, deleting, removing
 * at last one char */
int one_way(const char* str1, const char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2), i, j;
    int nchars = 0;
    const char *tmp;

    if (abs(len1 - len2) > 1) return 0;

    /*if the strings have equal length check all chars with a tolerance
     * of one*/
    if (len1 == len2) {
        for (i = 0; i < len1; ++i)
            if (str1[i] != str2[i]) {
                ++nchars;
                if (nchars > 1) return 0;
            }
        return 1;
    }

    /* swap the strings if str1 > str2 so add max one char if the 
     * two chars in the same position are different*/
    if (len1 > len2) {
        tmp = str1;
        str1 = str2;
        str2 = tmp;
        len1 = len2;
    }
    for (i = 0, j = 0; i < len1; ++i, ++j) {
        if (str1[i] != str2[j]) {
            ++nchars;
            --i;
            if (nchars > 1) return 0;
        }
    }
    return 1;
}

int main() {
    printf("%d\n", one_way("pale", "ple"));
    printf("%d\n", one_way("pales", "pale"));
    printf("%d\n", one_way("pale", "bale"));
    printf("%d\n", one_way("pale", "bake"));
    return 0;
}
