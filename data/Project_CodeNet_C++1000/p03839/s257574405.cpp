#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("badhair.gir","r",stdin);freopen ("badhair.cik","w",stdout);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,t,dp[N],vis[N],pref[N],pref2[N],mn=-1e18;


int main()
{
	fast;
	cin>>n>>m;

	fs(ar,n);
	fo(i,1,n)
	if(ar[i]>0)
		sum+=ar[i];
	fo(i,1,n)
	{
		pref[i]=pref[i-1];
		pref2[i]=pref2[i-1];
		if(ar[i]>0)
			pref[i]-=ar[i];
		else
			pref2[i]+=ar[i];
	}
	fo(i,m,n)
	{
		mn=max(mn,pref[i]-pref[i-m]);
		mn=max(mn,pref2[i]-pref2[i-m]);
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<pref[i]<<sp;
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<pref2[i]<<sp;
	// cout<<endl;
	// cout<<mn<<endl;
	cout<<sum+mn<<endl;
	// ll a=0;
	// ll b=0;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/