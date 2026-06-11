#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll cost[2010];
ll res[2010]; 
int main()
{
	ll n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&cost[i]);
		res[i]=cost[i];
	}
	ll ans=inf;
	for(int k=0;k<n;k++)//xiugai k ci
	{
		ll temp=0;
		for(int i=1;i<=n;i++)//mei ge slime
		{
			ll low;
			if(i<=k)
			{
				low=min(res[i],cost[n-(k-i)]);
			}
			else
			{
				low=min(res[i],cost[i-k]);
			}
			res[i]=low;
			temp+=low;
		}
		temp+=k*x;
		ans=min(ans,temp);
	}
	printf("%lld",ans);
} 