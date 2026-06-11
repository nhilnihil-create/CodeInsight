#include <stdio.h>
int main () {
    char S[100];
    scanf("%s", S);
    char Y[] = "YAKI";
    for (int i = 0; i < 4; i++) {
        if (S[i] != Y[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}