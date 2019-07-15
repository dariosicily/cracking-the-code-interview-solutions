#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool helper_is_rotation(const char *s1, const char *s2, size_t sz) 
{
  
    for (size_t i = 0; i < sz; ++i)
        if (!strncmp(s1 + i, s2, sz)) {
            return true;
        }
    return false;
}
/* check if s1 is a rotation of s2, ex."erbottlewat" is a rotation of 
 * "waterbottle"*/
bool is_rotation(const char *s1, const char *s2) 
{
    size_t l1 = strlen(s1);
    size_t l2 = strlen(s2);
    if (l1 != l2) return false;
    if (!l1) return true;
    
    /*doubles1 will contain erbottlewaterbottlewat*/
    char *doubles1 = calloc(l1 * 2 + 1, sizeof(char));
    strncpy(doubles1, s1, l1);
    strncpy(doubles1 + l1, s1, l1);

    bool result = helper_is_rotation(doubles1, s2, l1);
    free(doubles1);
    return result;
}

int main(void) 
{
    printf("%d\n", is_rotation("", ""));
    printf("%d\n", is_rotation("", "a"));
    printf("%d\n", is_rotation("a", ""));
    printf("%d\n", is_rotation("a", "b"));
    printf("%d\n", is_rotation("erbottlewat", "bottlewater"));
    return 0;
}
