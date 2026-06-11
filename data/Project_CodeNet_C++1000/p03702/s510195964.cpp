#include <bits/stdc++.h>
using namespace std;
long long int ans[100010];
long long int num[100010];
long long int n,a,b;

bool check(long long t)
{
    long long cnt=0;
    for(long long int i=1;i<=n;i++)
        num[i]=ans[i];
    for(long long int i=1;i<=n;i++)
    {
        num[i]-=t*b;
    }
    long long more=a-b;
    for(long long int i=1;i<=n;i++)
    {
        if(num[i]>0)
        {
            if(num[i]%more) cnt+=(num[i]/more+1);
            else cnt+=num[i]/more;
        }
    }
    if(cnt<=t) return true;
    return false;
}

int main()
{
        scanf("%lld%lld%lld",&n,&a,&b);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&ans[i]);
        }
        long long sum;
        long long l=1,r=1e9,mid;
        long long nn;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid))
            {
                nn=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%lld\n",nn);
        return 0;
}
