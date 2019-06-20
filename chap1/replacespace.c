#include <stdio.h>
#include <string.h>

char *replace_space(char *s) {
    int i = 0, length;
    while(s[i]) {
        if (s[i] != ' ') ++i;
        else {
            length = strlen(s);
            /* move all the characters to the right by 2 positions */
            memmove(s + i + 3, s + i + 1, length -1 - i);
            s[length + 2] = '\0';
            strncpy(s + i, "%20", 3);
            i += 3;
        }
    }
    return s;
}


int main() {
    
   /* assume that string contains enough space to replace spaces with 
     * %20 */
   char s1[100] = " hello world! ";
   printf("%s\n", replace_space(s1));
   return 0;
}
