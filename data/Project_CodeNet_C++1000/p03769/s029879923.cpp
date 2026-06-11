# include <stdio.h>
int a[103], b[103];
int main()
{
    int p1=0, p2=0, m=100;
    long long n;
    scanf("%lld",&n);
    ++n;
    while(n > 1)
    {
        if(n&1) a[++p1] = m--, --n;
        else b[++p2] = m--, n>>=1;
    }
    printf("%d\n",p1+p2<<1);
    for(int i=1; i<=p1; ++i)
        printf("%d ",a[i]);
    for(int i=p2; i>=1; --i)
        printf("%d ",b[i]);
    for(int i=101-p1-p2; i<=100; ++i)
        printf("%d ",i);
    puts("");
    return 0;
}