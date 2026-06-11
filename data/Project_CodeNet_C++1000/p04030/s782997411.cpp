#include <stdio.h>

int main() {
    char s[15];
    char res[15] = {};
    scanf("%s", &s);
    int ct = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            res[ct] = '0';
            ct++;
        } else if (s[i] == '1') {
            res[ct] = '1';
            ct++;
        } else if (ct != 0) {
            if (s[i] == 'B') {
                res[ct - 1] = '\0';
                ct -= 2;
            }
            ct++;
        }
    }
    res[ct] = '\0';
    printf("%s", res);
}