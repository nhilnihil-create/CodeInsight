#include <stdio.h>

int main(void){
    // Your code here!
    int a,b,c;
    
    scanf("%d%d%d",&a,&b,&c);
    
    if(b-a == c-b){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
