#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(b - a == c - b){
        printf("YES""\n");
    }
    else{
        printf("NO""\n");
    }
    return 0;
}