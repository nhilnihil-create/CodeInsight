#include<cstdio>

int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    if (A < 14 && B < 14 && A > 0 && B > 0){
        if(A == 1 && B!= 1){
        printf("Alice");
    } else if (A != 1 && B == 1){
        printf("Bob");
    } else if (A != 1 && B != 1 && A > B){
        printf("Alice");
    } else if (A != 1 && B != 1 && A < B){
        printf("Bob");
     }else if (A == B){
         printf("Draw");
     }
     } 
    }
