#include <stdio.h>
#include <string.h>

int are_anagrams(const char *s1, const char *s2) {
    int alphabet[26] = {0};
    int index1, index2;
    size_t l1 = strlen(s1), l2 = strlen(s2), i;

    /*if the strings have different lenghts are not anagrams */
    if (l1 != l2) return 0;

    /* count the frequencies of characters */
    for (i = 0; i < l1; ++i) {
        index1 = s1[i] - 'a';
        index2 = s2[i] - 'a';
        ++alphabet[index1];
        --alphabet[index2];
    }
    /* all the alphabet letters should be 0, otherwise they are not
     * anagram */
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
