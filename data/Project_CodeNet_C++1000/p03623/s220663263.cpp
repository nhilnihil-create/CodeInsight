#include <stdio.h>

int main(){
    int x, a, b;
    scanf("%d %d %d", &x, &a, &b);
    
    int s, t;
    if(a >x){
        s = a - x;
    }
    else{
        s = x - a;
    }
    
    if(b > x){
        t = b - x;
    }
    else{
        t = x - b;
    }
    
    if(s > t){
        printf("B\n");
    }
    else{
        printf("A\n");
    }
    
    return 0;
}
