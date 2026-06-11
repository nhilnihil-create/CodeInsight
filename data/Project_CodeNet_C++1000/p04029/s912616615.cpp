#include<stdio.h>

int main(){
    int N,sum=0,summ=0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        sum+=1;
        summ+=sum;
    }
    printf("%d", summ);
    return 0;
}