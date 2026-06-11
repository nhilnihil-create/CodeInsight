#include <stdio.h>

int main(){

    int x,a,b;
    scanf("%d %d %d", &x, &a, &b);
    if(a>x){
        if(b>x){
            if((a-x)>(b-x)){
                printf("B\n");
            }
            else if((a-x)<(b-x)){
                printf("A\n");
            }
        }
        else if(b<x){
            if((a-x)>(x-b)){
                printf("B\n");
            }
            else if((a-x)<(x-b)){
                printf("A\n");
            }
        }
    }
    else if(a<x){
        if(b>x){
            if((x-a)>(b-x)){
                printf("B\n");
            }
            else if((a-x)<(b-x)){
                printf("A\n");
            }
        }
        else if(b<x){
            if((x-a)>(x-b)){
                printf("B\n");
            }
            else if((a-x)<(x-b)){
                printf("A\n");
            }
        }
    }



    return 0;
}