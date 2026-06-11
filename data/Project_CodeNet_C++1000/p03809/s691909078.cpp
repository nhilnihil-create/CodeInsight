#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll n,c[N];vector<ll> E[N];
ll dfs(ll x,ll fr)
{
	if(E[x].size()==1) return c[x];
	ll s=0,mx=0,w;
	for(auto R:E[x]) if(R!=fr) w=dfs(R,x),mx=max(mx,w),s+=w;
	mx*2<=s?mx=s/2:mx=s-mx;
	if(c[x]>s||c[x]<s-mx) puts("NO"),exit(0);
	w=s-c[x];w=s-2*w;
	if(w<0) puts("NO"),exit(0);
	return w;
}
int main()
{
	cin>>n;for(ll i=1;i<=n;i++) cin>>c[i];
	if(n==2) c[1]==c[2]?puts("YES"):puts("NO"),exit(0);
	for(ll i=1,x,y;i<n;i++) cin>>x>>y,E[x].push_back(y),E[y].push_back(x);
	for(ll i=1;i<=n;i++) if(E[i].size()>1) dfs(i,0)?puts("NO"):puts("YES"),exit(0);
}
