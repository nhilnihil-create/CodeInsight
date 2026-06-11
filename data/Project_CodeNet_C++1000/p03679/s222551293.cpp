#include<stdio.h>
int main()
{
    long long A,B,X;
    scanf("%lld %lld %lld",&X,&A,&B);
    if(A-B>=0)
    {
        printf("delicious");
    }
    else if(A-B>=-X)
    {
        printf("safe");
    }
    else if(A-B<-X)
    {
        printf("dangerous");
    }
    return 0;
}