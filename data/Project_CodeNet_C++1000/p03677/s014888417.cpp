#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<61);
const int inf=(1<<30);
const int nmax=1e5+50;
const int mod=1e9+7;
using namespace std;
int n,m,i;
ll a[nmax],c[nmax],v[nmax],ans=llinf;
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<n;i++)
	{
		if(a[i]<a[i+1])
		{
			c[1]+=a[i+1]-a[i];
			c[a[i]+1]-=(a[i+1]-a[i]);
			c[a[i+1]+1]+=a[i+1]-a[i];
			c[a[i]+1]+=a[i+1]+1;
			c[a[i+1]+1]-=(a[i+1]+1);
			v[a[i]+1]++;
			v[a[i+1]+1]--;
		}
		else
		{
			c[1]+=a[i+1]+1;
			c[a[i+1]+1]-=(a[i+1]+1);
			c[a[i+1]+1]+=m+a[i+1]-a[i];
			c[a[i]+1]-=(m+a[i+1]-a[i]);
			c[a[i]+1]+=m+1+a[i+1];
			v[1]++;
			v[a[i+1]+1]--;
			v[a[i]+1]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		c[i]+=c[i-1];
		v[i]+=v[i-1];
		ans=min(ans,c[i]-v[i]*i);
	}
	cout<<ans<<endl;
    return 0;
}