#include<stdio.h>
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    A=A+B;
    if(A<10){
        printf("%d",A);
    }
    else{
        printf("error");

    }
    return 0;
}
