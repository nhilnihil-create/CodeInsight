
# include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int maxn = 1e5;
int n, a, b, m[maxn+3];
 
bool judge(LL x)
{
    LL sum = 0;
    for(int i=0; i<n; ++i)
    {
        LL t = (LL)m[i]-x*b;
        if(t>0)
        {
            sum += (int)ceil(t*1.0/(a-b));
            if(sum > x || sum < 0)
                return false;
        }
    }
    return true;
}
int main()
{
    while(~scanf("%d%d%d",&n,&a,&b))
    {
        int imax = 0;
        for(int i=0; i<n; ++i) scanf("%d",&m[i]), imax = max(imax, m[i]);
        LL l=0, r=imax;
        while(l<r)
        {
            LL mid = l+r>>1;
            if(judge(mid)) r=mid;
            else l=mid+1;
        }
        printf("%lld\n",r);
    }
    return 0;
}