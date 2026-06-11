#include <cstdio>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i)
using namespace std;

typedef long long LL;
int head,tail,q[210],m,a[110];
LL n;

int main()
{
    scanf("%lld",&n);
    head=100,tail=99;
    while (n)
        if (n&1)
            n>>=1,a[++m]=1;
        else
            --n,++m;
    repd(i,m,1)
        (a[i]?q[++tail]:q[--head])=m-i+1;
    printf("%d\n",m*2);
    repu(i,head,tail)
        printf("%d ",q[i]);
    repu(i,1,m)
        printf("%d ",i);
    return 0;
}