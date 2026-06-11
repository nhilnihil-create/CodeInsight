#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i)
using namespace std;

typedef long long LL;
int n,m,d[100100],p[100100],a[100100],ans[100100];
LL k;
bool flag[100100];

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

int main()
{
    n=getint()-1;
    repu(i,0,n)
        d[i]=getint();
    repd(i,n,1)
        d[i]-=d[i-1];
    repu(i,1,n)
        p[i]=i;
    for (scanf("%d%lld",&m,&k); m--;)
    {
        int x=getint();
        swap(p[x],p[x-1]);
    }
    repu(i,1,n)
        if (!flag[i])
        {
            flag[a[0]=i]=1,m=1;
            for (int j=p[i]; j!=i; flag[a[m++]=j]=1,j=p[j]);
            repu(j,0,m-1)
                ans[a[j]]=a[(j+k)%m];
        }
    LL sum=d[0];
    printf("%lld\n",sum);
    repu(i,1,n)
        printf("%lld\n",sum+=d[ans[i]]);
    return 0;
}