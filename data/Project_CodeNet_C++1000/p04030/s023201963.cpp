#include <stdio.h>

int main() {
    int idx = 0;
    char c, str[20];
    while (scanf("%c", &c) && c != '\n') {
        if (c == '0' || c == '1') {
            str[idx++] = c;
        }
        else {
            idx--;
            if (idx < 0) {
                idx = 0;
            }
        }
    }
    str[idx] = '\0';
    printf("%s\n", str);
    return 0;
}
