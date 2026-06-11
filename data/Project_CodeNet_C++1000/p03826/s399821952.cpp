#include <stdio.h>
int main(void){
    // Your code here!
    int A,B,C,D;
    
    scanf("%d%d%d%d",&A,&B,&C,&D);
    
    if(A*B >= C*D){
        printf("%d\n",A*B);
    }
    else{
        printf("%d\n",C*D);
    }
}
