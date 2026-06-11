#include <stdio.h>

int main() {
    int aaa, bb, cc;
    scanf("%d %d %d", &aaa, &bb, &cc);
   int i = aaa-bb;
   int j = aaa-cc;
 
   
    if(i<0){
        i = -i;
    }
    if(j<0){
        j = -j;
    }
    
    if(i == -i){
        i *= -1;
    }
   if(j == -j){
       j *= -1;
   }
    if(i < j){
        printf("A");
    }
    else{
        printf("B");
    }

    return 0;
}