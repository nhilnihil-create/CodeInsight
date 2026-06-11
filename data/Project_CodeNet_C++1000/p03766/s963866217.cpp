#include <cstdio>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

typedef long long LL;
const int p=1000000007;
int n,f[1000100],ans;

int main()
{
    scanf("%d",&n);
    f[0]=1,f[1]=p-1;
    repu(i,0,n-1)
    {
        (f[i+1]+=f[i])%=p;
        (f[i+2]+=p-f[i])%=p;
        (f[i+3]+=f[i])%=p;
        int t=n-i-1;
        if (i<n-1)
        {
            ans=(ans+LL(n-1)*(n-1)%p*f[i])%p;
            ans=(ans+LL(n-t)*f[i])%p;
        }
        else
            ans=(ans+LL(n-1)*f[i])%p;
        (f[i+1]+=f[i])%=p;
    }
    (ans+=f[n])%=p;
    printf("%d\n",ans);
    return 0;
}