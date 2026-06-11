#include <stdio.h>
int main(){
    int limit;
    scanf("%d", &limit);
    int total = 0;
    for(int i = 1; i <= limit; i++){
        total = total + i;
    }
    printf("%d\n", total);
    return 0;
}