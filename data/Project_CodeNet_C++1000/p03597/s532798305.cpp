/* ex2_3
   YSK722 */

#include <stdio.h>

int main(void){
    int n, a;
    scanf("%d", &n);
    scanf("%d", &a);
    if(n < 1 || 100 < n){
        return 1;
    }
    if(a < 0 || n * n < a){
        return 1;
    }
    printf("%d\n", n * n - a);
    return 0;
}