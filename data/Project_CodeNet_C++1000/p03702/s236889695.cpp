#include<bits/stdc++.h>
#define LL long long int
using namespace std;
const int maxn=1e5+7;
int n,a,b;
int H[maxn];
bool judge(LL mid)
{
    LL mul=mid*b;
    LL sum=0;
    for(int i=n;i>=1;i--)
    {
        if(H[i]>mul)
        {
            if((H[i]-mul)%(a-b))
                sum+=(H[i]-mul)/(a-b)+1;
            else
                sum+=(H[i]-mul)/(a-b);
        }
    }
    return sum<=mid;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    LL r=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&H[i]);
        r+=H[i]/b+1;
    }
    sort(H+1,H+n+1);
    LL l=1;
    while(l<r)
    {
        LL mid=(l+r)>>1;
        if(judge(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
