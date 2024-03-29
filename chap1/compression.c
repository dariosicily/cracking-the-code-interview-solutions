#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* reverse:  reverse string s in place */
void reverse(char s[]) {
 
     for (size_t i = 0, j = strlen(s) - 1; i < j; i++, j--) {
         char c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

/* itoa:  convert n to characters in s */
void itoa(int n, char s[]) {
     size_t i = 0; 
     do {       
         s[i++] = n % 10 + '0';   
     } while ((n /= 10) > 0);     
     s[i] = '\0';
     reverse(s);
 }


/* a function that compress the original string and store the compressed
 * string in compress ex. aabcccccaaa will become a2blc5a3. If the 
 * compressed string is longer than the original it returns the 
 * original string*/
const char *compression(const char *original, char *compress) {
    
    /*have to check the length of the buffer to determine the maximum
     * length*/
    char buffer[100];
    
    /*memorize the first char of original in compress*/
    char previous = original[0];
    size_t len = strlen(original) + 1;
    size_t nc = 1;

    for (size_t i = 1, j = 0; i < len; ++i) {
        if (original[i] == previous) {
            ++nc;
        } else {
            itoa(nc, buffer);
            size_t lenbuffer = strlen(buffer);
            if (1 + lenbuffer + strlen(compress) >= len) return original;
            compress[j++] = previous;
            strncpy(compress + j,buffer, lenbuffer);
            j += strlen(buffer);
            nc = 1;
            previous = original[i];
        }

    }

    return compress;
}

int main(void) {
    char *original = "aabcccccaaa";
    char *compressed = calloc(strlen(original) + 1, sizeof(char));
    printf("%s\n", compression(original, compressed));
    free(compressed);
    return 0;
}
