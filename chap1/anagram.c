#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


/*helper function called in the function are_anagrams*/
static void count_frequencies(const char * s, int * alphabet, int addend) 
{
    char ch;
    while ((ch = *s++) != 0) {
        if (islower(ch)) {
            alphabet[ch - 'a'] += addend;
        }
    }
}


/*check if one string is an anagram of another, it uses an int array
 * called alphabet to store frequencies of chars in both strings, add
 * 1 for s1 and subtract 1 for s2*/
bool are_anagrams(const char *s1, const char *s2) 
{
    int alphabet[26] = { 0 };

    /* count the frequencies of characters */
    count_frequencies(s1, alphabet, 1);
    count_frequencies(s2, alphabet, -1);

    /* all the alphabet letters should be 0, otherwise the strings are not
     * anagrams */
    for (size_t i = 0; i < 26; ++i) {
        if (alphabet[i] != 0) return false;
    }

    return true;
}

int main(void) 
{
    char s1[] = "aaabbbccc";
    char s2[] = "aabbaccbc";
    printf("%d\n", are_anagrams(s1, s2));
    return 0;
}
