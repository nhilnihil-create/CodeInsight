#include <stdio.h>

int main(void){
    // Your code here!
    int a,b,c;
    int max,sum=0;
    
    scanf("%d%d%d",&a,&b,&c);
    
    if(a > b ){
        max = a;
    }
    else{
        max = b;
    }
    
    if(c > max){
        max = c;
    }

    if(max == (a+b+c-max)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
