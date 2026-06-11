#include <cstdio>

int main()
{
    int len=0,slen=0;
    long long N;
    static bool a[50],b[101];

    scanf("%lld",&N);
    for (int i=0;i<50;++i)
        a[i]=0;
    for (int i=0;i<101;++i)
        b[i]=0;

    for (N=N+1;N>1;N=N>>1)
    {
        len++;
        slen++;
        if (N&1)
        {
            a[len]=1;
            slen++;
        }
    }
    printf("%d\n",slen<<1);
    for (int i=1;i<=len;++i)
    {
        if (a[i])
        {
            printf("%d ",101-i);
            b[101-i]=1;
        }
        printf("%d ",i);
        b[i]=1;
    }
    printf("1");
    for (int i=2;i<=100;++i)
        if (b[i]) printf(" %d",i);

    return 0;
}
