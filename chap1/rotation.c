#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*check if s1 is a substring of s2 */
int substring(const char *s1, const char *s2) {
    int l1 = strlen(s1);
    int difference = strlen(s2) - l1, i;
    if (difference < 0) return 0;
    for (i = 0; i < difference; ++i)
        if (!strncmp(s1, s2 + i, l1)) return 1;
    return 0;
}

int is_rotation(const char *s1, const char *s2) {
    size_t l1 = strlen(s1), l2 = strlen(s2);
    int result = 0;
    char *double_s2 = 0;
    if (l1 != l2) return 0;
    double_s2 = malloc(sizeof(char) * (l2 * 2 + 1));
    double_s2[l2 * 2] = '\0';
    strncpy(double_s2, s2, l2);
    strncpy(double_s2 + l2, s2, l2);
    result = substring(s1, double_s2);
    free(double_s2);
    return result;
}

int main() {
    char s1[] = "waterbottle";
    char s2[] = "erbottlewat";
    printf("%d\n", is_rotation(s1, s2));
    return 0;
}
