#include<bits/stdc++.h> 
#define LL long long
#define MOD 1e9+7
#define pi acos(-1.0)
#define ULL unsigned long long
#define mem_1(str) memset(str,-1,sizeof(str))
#define mem0(str) memset(str,0,sizeof(str))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
using namespace std;
LL num[200000];
LL n,a,b;
bool check(LL x) 
{
    LL sum=0;
    LL q=a-b;
    for(int i=1;i<=n;i++) 
	{
        LL now=num[i]-b*x;
        if(now<=0) continue;
        else 
		{
            sum+=now/q;
            if(now%q) sum++;
            if(sum>x) return false;
        }
    }
    if(sum>x) return false;
    return true;
}
int main() 
{
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i=1;i<=n;i++) 
	{
        scanf("%lld",&num[i]);
    }
    LL l=1,r=(LL)1e9;
    LL ans=0;
    while(l<=r) {
        LL mid = (l + r)/2;
        if(check(mid)) 
		{
			r=mid-1;
			ans=mid;
		}
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}