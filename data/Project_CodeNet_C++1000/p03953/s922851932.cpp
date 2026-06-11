#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i)
using namespace std;

typedef long long LL;
int n,m,d[100100],f[60][100100],ans[100100];
LL k;

int getint()
{
    char ch;
    while (!isdigit(ch=getchar()) && ch!='-');
    bool flag=ch=='-';
    if (flag)
        ch=getchar();
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return flag?-x:x;
}

void merge(int *f,int *g,int *h)
{
    repu(i,1,n)
        h[i]=f[g[i]];
}

int main()
{
    n=getint()-1;
    repu(i,0,n)
        d[i]=getint();
    repd(i,n,1)
        d[i]-=d[i-1];
    repu(i,1,n)
        f[0][i]=ans[i]=i;
    for (scanf("%d%lld",&m,&k); m--;)
    {
        int x=getint();
        swap(f[0][x],f[0][x-1]);
    }
    repu(i,0,59)
    {
        if (k&1)
            merge(f[i],ans,ans);
        if (!(k>>=1))
            break;
        merge(f[i],f[i],f[i+1]);
    }
    LL sum=d[0];
    printf("%lld\n",sum);
    repu(i,1,n)
        printf("%lld\n",sum+=d[ans[i]]);
    return 0;
}