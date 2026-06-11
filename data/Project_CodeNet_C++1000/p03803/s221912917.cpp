#include <stdio.h>
int main(void){
    // Your code here!
    int A,B;
    
    scanf("%d%d",&A,&B);
    
    if(A == B){
        printf("Draw\n");
    }
    else if(A == 1){
        printf("Alice\n");   
    }
    else if(B == 1){
        printf("Bob\n");
    }
    else if(A > B){
        printf("Alice\n");
    }
    else{
        printf("Bob\n");
    }
    
    
    
}
