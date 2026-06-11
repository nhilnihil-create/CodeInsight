#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 800010
using namespace std;
ll n,k,val[N],ans=0,sz;
vector<ll> st,sum;
void update(ll x)
{
	ll pos;
	pos=lower_bound(st.begin(),st.end(),x)-st.begin();
	pos+=sz;
	while(pos>0)
	{
		val[pos]++;
		pos>>=1;
	}
	return;
}
ll getans(ll x,ll l,ll r,ll v)
{
	if(st[r]<v)
	{
		return 0;
	}
	if(st[l]>=v)
	{
		return val[x];
	}
	ll mid=(l+r)>>1;
	return getans(x*2,l,mid,v)+getans(x*2+1,mid+1,r,v);
}
int main(){
	ll i,a;
	cin>>n>>k;
	sum.push_back(0);
	for(i=0;i<n;i++)
	{
		cin>>a;
		a-=k;
		sum.push_back(sum[sum.size()-1]+a);
		st.push_back(sum[sum.size()-1]);
	}
	sort(st.begin(),st.end());
	memset(val,0,sizeof(val));
	for(sz=1;sz<=st.size();)
	{
		sz*=2;
	}
	while(st.size()<sz)
	{
		st.push_back(st[st.size()-1]);
	}
	for(i=n;i>=0;i--)
	{
		ans+=getans(1,0,sz-1,sum[i]);
		update(sum[i]);
	}
	cout<<ans<<endl;
	return 0;
}