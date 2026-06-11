#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define pr make_pair
#define X first
#define Y second
typedef long long ll;
ll h,w,n;
ll x,y,s=0;
map <pair<ll,ll>,ll> mp;
int dx[]={-1,0,0,1,-1};
int dy[]={-1,1,-1,0,0};
ll ans[12];
int main()
{
	scanf("%lld%lld%lld",&h,&w,&n);
	ans[0]=1ll*(h-2)*(w-2);
	while(n--)
	{
		scanf("%lld%lld",&x,&y);
		for(ll i=max(x-2,1ll);i<=min(h-2,x);i++)
			for(ll j=max(y-2,1ll);j<=min(w-2,y);j++)
				mp[pr(i,j)]++;
	}
	for(map<pair<ll,ll>,ll>::iterator it=mp.begin(),ed=mp.end();it!=ed;it++)
		ans[it->second]++,s++;
	ans[0]-=s;
	for(int i=0;i<=9;i++)
		printf("%lld\n",ans[i]);
	return 0;
}