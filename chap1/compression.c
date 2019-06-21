#include <stdio.h>
#include <string.h>

/* a function that compress the original string and store the compressed
 * string in compress ex. aabcccccaaa will become a2blc5a3. If the 
 * compressed string is longer than the original it returns the 
 * original string*/
const char *compression(const char *original, char *compress) {
    int len, i, j, nc;
    
    /*memorize the first char of original in compress*/
    char previous = original[0];
    len = strlen(original);
    nc = 1;

    for (i = 1, j = 0; i < len; ++i) {
        if (original[i] == previous) {
            ++nc;
        } else {
            compress[j++] = previous;
            compress[j++] = nc + '0';
            nc = 1;
            previous = original[i];

        }

    }
    /* there are characters still in the stream */
    compress[j++] = previous;
    compress[j++] = nc + '0';
    compress[j] = '\0';

    if ((int)strlen(compress) >= len) return original;
    return compress;
}

int main() {
    char buffer[20] = {0};
    printf("%s\n", compression("aabcccccaaa", buffer));
    return 0;
}
