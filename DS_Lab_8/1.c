/*
   Write a program to reverse the individual word of a given sentence.
   time complexity - O(n).
   space complexity - O(1).
*/

#include <stdio.h>
#include <string.h>
void reverseWords(char *s) {
    int st = 0,en = 0;
    while (s[en]) {
        if (s[en] != ' ') en++; 
        else {
            for (int i = st, j = en - 1; i < j; i++, j--) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
            st = en + 1;
            en = st;
        }
    }
    for (int i = st, j = en - 1; i < j; i++, j--) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
int main() {
    char s[] = "Sun rises in the east";
    reverseWords(s);
    printf("%s\n", s);
    return 0;
}
/*
   Output : nuS sesir ni eht tsae
*/
