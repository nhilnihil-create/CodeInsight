#include <stdio.h>
 
int main(){
 
    int x,A,B,c,d;
    scanf("%d %d %d",&x,&A,&B);
    
    c = x >= A ? x - A : A - x;
    d = x >= B ? x - B : B - x;
    
    if(c<d) {
        printf("A\n");
    }
    else { 
        printf("B\n");
    }
 
  return 0;
}