#include <stdio.h>
int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(0 <= b - c){
        printf("delicious");
    }
    else{
        if(a >= c - b)
            printf("safe");
    else{
        printf("dangerous");
    }        
    }
    return 0;
    
}
