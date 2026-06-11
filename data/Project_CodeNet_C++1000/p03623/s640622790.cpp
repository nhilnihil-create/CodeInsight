#include <stdio.h>

int main(){
    int x,a,b;
    scanf ("%d %d %d", &x, &a, &b);
    int ans1, ans2;
    
    if(x-a<0){
        ans1 = (x-a) * -1; //998
    } else if(x-a>=0){
        ans1 = x-a;
    }
    
    if(x-b<0){
        ans2 = (x-b) * -1; //999
    } else if(x-b>=0){
        ans2 = x-b;
    }

    if(ans1 < ans2){
        printf("A\n");
    } else {
        printf("B\n");
    }

}