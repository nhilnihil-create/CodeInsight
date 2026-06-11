#include <stdio.h>
int main(void){
    // Your code here!
    int W,a,b;
    
    scanf("%d%d%d",&W,&a,&b);
    
    if(a > b){ //a < b
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    if(a+W >= b){
        printf("0\n");
    }
    else{
        printf("%d\n",b-(a+W));
    }
    
    return 0;
}
