#include <bits/stdc++.h>
#define N 305
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
#define ull unsigned long long int
using namespace std;

ll n,m,ar[N][N],sum=1e18,t,tut[N],cnt[N],mark[N];

int main()
{
	fast;
	cin>>n>>m;
	fo(i,1,n)
	tut[i]=1;
	fo(i,1,n)
		fo(j,1,m)
			cin>>ar[i][j];
	ll x=m-1;
	while(x--)
	{
		ll mk=0;
		ll mki=0;
		fo(i,1,m)
			cnt[i]=0;
		fo(i,1,n)
		{
			ll x=ar[i][tut[i]];
			cnt[x]++;
			if(cnt[x]>mk)
			{
				mk=cnt[x];
				mki=x;
			}
		}
		// cout<<mk<<sp<<mki<<endl;
		mark[mki]=1;
		fo(i,1,n)
		{
			while(mark[ar[i][tut[i]]])
				tut[i]++;
		}
		sum=min(sum,mk);
	}
	if(m==1)
		sum=n;
	cout<<sum<<endl;


}

