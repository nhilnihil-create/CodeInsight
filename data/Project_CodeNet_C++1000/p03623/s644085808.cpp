#include <stdio.h>
 
int main(){

    int x,a,b,c,d;
    scanf("%d %d %d",&x,&a,&b);
    
    c = x >= a ? x - a : a - x;
    d = x >= b ? x - b : b - x;
    
    if(c<d) {
        printf("A\n");
    }
    else { 
        printf("B\n");
    }

  return 0;
}