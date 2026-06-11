#include <stdio.h>
#include <string.h>

int main() {
    int index = 0;
    char s[11], output[11];
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            output[index] = '0';
            index++;
        } else if (s[i] == '1') {
            output[index] = '1';
            index++;
        } else if (s[i] == 'B') {
            if (index > 0) {
                index--;
                output[index] = '\0';
            }
        }
    }

    output[index] = '\0';
    printf("%s", output);
    
    return 0;
}