#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*One away : There are three types of edits that can be performed on strings:
insert a character, remove a character and replace a character.
Given two strings, write a function to check if they are one edit (or zero edits) away.*/
static bool helper_one_away(const char *a, const char *b,
                           bool allow_deletion)
{
    size_t nchars = 0;
    while (*a) {
        if (*a++ != *b++) {
            if (++nchars > 1) return false;
            if (allow_deletion) --b;
        }
    }
    return true;
}

/* Return true if a can be obtained from b by adding,
   deleting, or replacing at most one character */
bool one_away(const char *a, const char *b)
{
    switch (strlen(a) - strlen(b)) {
    case (size_t)-1: return helper_one_away(b, a, true);
    case 0:          return helper_one_away(a, b, false);
    case 1:          return helper_one_away(a, b, true);
    default:         return false;
    }
}


int main(void) 
{
    printf("%d\n", one_away("pale", "ple"));
    printf("%d\n", one_away("pales", "pale"));
    printf("%d\n", one_away("pale", "bale"));
    printf("%d\n", one_away("pale", "bake"));
    printf("%d\n", one_away("pale", "ale"));
    return 0;
}
