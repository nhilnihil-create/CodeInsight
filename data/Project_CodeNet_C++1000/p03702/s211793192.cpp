# include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n, a, b;
LL m[100003];

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
    while(scanf("%d%d%d",&n,&a,&b)!=EOF)
    {
        LL max1=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
            max1=max(max1,m[i]);
        }
        LL l=0,r=max1;
        while(l<r)
        {
            LL mid=(r+l)/2;
            if(judge(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%lld",r);
    }
    return 0;
}
