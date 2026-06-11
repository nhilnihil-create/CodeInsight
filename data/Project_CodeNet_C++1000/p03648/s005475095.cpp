#include<cstdio>
int main()
{
    long long k;
    scanf("%lld",&k);
    printf("50\n");
    long long n=k/50,t=k%50;
    for(int i=0; i<50; i++)
    {
        if(i!=0)
            printf(" ");
        if(i<t) 
            printf("%lld",i+n+50-t+1);
        else 
            printf("%lld",i+n-t);
    }
    printf("\n");
    return 0;
}
