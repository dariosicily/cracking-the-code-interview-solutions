#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int helper_one_way(const char *str1, const char * str2, 
                          size_t len1, size_t flag) {
    size_t nchars = 0;
    size_t i, j;
 
    for (i = 0, j = 0; i < len1; ++i, ++j) {
        if (str1[i] != str2[j]) { 
            if (++nchars > 1) return 0;
            if (flag && i) --i;
        }
    }
    return 1;
}

/* check if str1 can be obtained from string2 adding, deleting, removing
 * at last one char */
int one_way(const char *str1, const char *str2) {
    size_t len1 = strlen(str1), len2 = strlen(str2);
    size_t diff = abs(len1 - len2);
    const char *tmp;

    if (diff > 1) return 0;
    if (!diff) return helper_one_way(str1, str2, len1, 0);

    /* swap the strings if len1 > len2 so str1 is always shorter than str2 
     * add max one char to str1 if the two chars in 
     * the same position are different*/
    if (len1 > len2) {
        tmp = str1;
        str1 = str2;
        str2 = tmp;
        len1 = len2;
    }
    
    return helper_one_way(str1, str2, len1, 1); 
}

int main(void) {
    printf("%d\n", one_way("pale", "ple"));
    printf("%d\n", one_way("pales", "pale"));
    printf("%d\n", one_way("pale", "bale"));
    printf("%d\n", one_way("pale", "bake"));
    return 0;
}
