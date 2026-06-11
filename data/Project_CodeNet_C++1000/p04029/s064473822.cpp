#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    
    while(n){
        sum += n;
        n--;
    }
    
    printf("%d\n", sum);
    
    return 0;
}
