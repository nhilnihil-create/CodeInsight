#include <stdio.h>
#include <string.h>

void hekerman(char x[105]);

int main() {

    char x[105];

    scanf("%s", x);

    hekerman(x);

    return 0;
}

void hekerman(char x[105]) {

    int i, cnt = 0;
    char y[105];
    
    for(i = 0; i < strlen(x); i++) {
        if(x[i] == 'B') {
            cnt--;
        } else {
            y[cnt++] = x[i];
        }

        if(cnt < 0) {
            cnt = 0;
        }
    }

    for(i=0; i<cnt; i++) {
        printf("%c", y[i]);
    }
    printf("\n");

}