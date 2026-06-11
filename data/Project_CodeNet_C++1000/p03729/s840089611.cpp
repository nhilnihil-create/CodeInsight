#include <stdio.h>
#include <string.h>

int main (){

    char A[12],B[12],C[12];
    scanf("%s %s %s", A, B ,C);
    for(int i = 0; i < strlen(A); i++){
        if(A[i] >= 'A' && A[i] <= 'Z'){
            return 1;
        }
    }
    for(int i = 0; i < strlen(B); i++){
        if(B[i] >= 'A' && B[i] <= 'Z'){
            return 1;
        }
    }
    for(int i = 0; i < strlen(C); i++){
        if(C[i] >= 'A' && C[i] <= 'Z'){
            return 1;
        }
    }
    if (A[strlen(A)-1] == B[0] && B[strlen(B)-1] == C[0]){
        printf("YES\n");
    }else {
        printf("NO\n");
    }


    return 0;
}