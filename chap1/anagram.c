#include <stdio.h>
#include <string.h>

/*check if one string is an anagram of another, it uses an int array
 * called alphabet to store frequencies of chars in both strings, add
 * 1 for s1 and subtract 1 for s2*/
int are_anagrams(const char *s1, const char *s2) {
    int alphabet[26] = { 0 };
    int index1, index2;
    size_t l1 = strlen(s1), l2 = strlen(s2), i;

    /*if the strings have different lengths are not anagrams */
    if (l1 != l2) return 0;

    /* count the frequencies of characters */
    for (i = 0; i < l1; ++i) {
        index1 = s1[i] - 'a';
        index2 = s2[i] - 'a';
        ++alphabet[index1];
        --alphabet[index2];
    }
    /* all the alphabet letters should be 0, otherwise the strings are not
     * anagrams */
    for (i = 0; i < 26; ++i)
        if (alphabet[i] != 0) return 0;
    
    return 1;
}

int main() {
    char s1[] = "aaabbbccc";
    char s2[] = "aabbaccbc";
    printf("%d\n", are_anagrams(s1, s2));
    return 0;
}
