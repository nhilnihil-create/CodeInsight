#include <cstdio>
#include <cctype>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i)
using namespace std;

typedef long long LL;
int n,m,x,y;
LL sum[100100],ans;

int getint()
{
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return x;
}

int main()
{
    scanf("%d%d%d",&n,&m,&y),ans=1LL<<60;
    while (--n)
    {
        x=y,y=getint();
        if (x<=y)
        {
            ++sum[y],--sum[x];
            sum[m]+=y-x,sum[m-1]-=y-x,sum[y]-=y-x,sum[y-1]+=y-x;
        }
        else
        {
            ++sum[y],++sum[m],--sum[x];
            sum[m]+=y,sum[m-1]-=y;
            sum[y]-=y+m-x,sum[y-1]+=y+m-x;
        }
    }
    repd(i,m,1)
        sum[i]+=sum[i+1];
    repd(i,m,1)
        ans=min(ans,sum[i]+=sum[i+1]);
    printf("%lld\n",ans);
    return 0;
}