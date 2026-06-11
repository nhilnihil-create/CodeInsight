#include <stdio.h>

int cnt = 0;
int p = 0;
char c;

int main(void){
    while(true){
       c = getchar();
       if(c == '\n') break;
       if(c == 'p') p++;
       cnt++; 
    }
    printf("%d\n", cnt/2 - p);
    return 0;
}
