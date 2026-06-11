#include <bits/stdc++.h>
using namespace std;
/*---define tricks---*/
#define ALL(v) v.begin(),v.end()
#define UN(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(x,y) memset(x,y,sizeof(x))
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define revsort(b,e) sort(b,e),reverse(b,e)
/*---define types---*/
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
/*---define variables---*/
ll n;
ll h[100005],t[100005];
ll a,b,L=1ll,R,ans,mid;
/*---define function---*/

bool check(ll x)
{
	ll res=0ll;
	memcpy(t,h,sizeof(h));
	ll damage=x*b;
	for(ll i=1;i<=n;++i)
	{
		t[i]-=damage;
	}
	ll dif=a-b;
	for(ll i=1;i<=n;++i)
	{
		if(t[i]>0)
		{
			if(t[i]%dif!=0)
			{
				res+=t[i]/dif+1;
			}
			else
			{
				res+=t[i]/dif;
			}
		}

	}
	return res<=x;
}

/*---main code---*/
int main()
{
	FIO;
	cin>>n>>a>>b;
	for(int i=1;i<=n;++i)
	{
		cin>>h[i];
	}
	sort(h+1,h+n+1);
	R=1e10;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))
		{
			ans=mid;
			R=mid-1;
		}
		else
		{
			L=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
