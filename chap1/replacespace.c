#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static size_t str_urlified_len(const char *src) 
{
    size_t nspaces = 0;
    size_t length = 0;
    while(*src) {
        if (*src == ' ') {
            ++nspaces;
        }
        ++length;
        ++src;
    }
    return length + nspaces * 3;
}

char *replace_space(char *dest, const char *src) 
{
    size_t i = 0;

    while(*src) {
        char c = *src;
        if (c == ' ') {
            strncpy(dest + i, "%20", 3);
            i += 3;
        } else {
            dest[i++] = c;
        }
        ++src;
    }
    return dest;
}

char *replace_space_alt(const char *src) {
    size_t destlen= str_urlified_len(src);
    char *dest = calloc(destlen + 1, sizeof(char));
    return replace_space(dest, src);
}


int main(void) 
{
    
   char *src = " hello world! ";
   /* assume that string contains enough space to replace spaces with 
     * %20 , the user should controll the dimension of string before 
     * using the function replace_space, but the advantage is that 
     * dest string can be indifferently on stack or heap*/
   char *dest = calloc(str_urlified_len(src) + 1, sizeof(char));
   printf("%s\n", replace_space(dest, src));
   free(dest);

   /*in this case dest is returned from malloc inside replace_space_alt
    * and so the user cannot use string on the stack*/
   dest = replace_space_alt(src);
   printf("%s\n", dest);
   free(dest);
   return 0;
}
