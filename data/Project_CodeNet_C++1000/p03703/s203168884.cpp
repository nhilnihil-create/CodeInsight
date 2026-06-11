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
#define N 200010
using namespace std;
ll n,k,a[N],bit[N],ans=0;
vector<ll> sum;
void update(ll x)
{
	x++;
	while(x<=n)
	{
		bit[x]++;
		x+=(x&(-x));
	}
	return;
}
ll getans(ll x)
{
	ll ret=0;
	x++;
	while(x>0)
	{
		ret+=bit[x];
		x-=(x&(-x));
	}
	return ret;
}
int main(){
	ll i,x=0,pos;
	cin>>n>>k;
	memset(bit,0,sizeof(bit));
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]-=k;
		x+=a[i];
		sum.push_back(x);
	}
	sort(sum.begin(),sum.end());
	sum.erase(unique(sum.begin(),sum.end()),sum.end());
	x=0;
	for(i=0;i<=n;i++)
	{
		pos=lower_bound(sum.begin(),sum.end(),x)-sum.begin();
		x+=a[i];
		ans+=getans(pos);
		update(pos);
	}
	cout<<ans<<endl;
	return 0;
}