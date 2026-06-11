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

ll n,m,ar[N],sum,t,tut[N];

bool check(ll x)
{
	for(int i=1;i<=m;i++)
	{
		tut[i]=0;
		if(ar[i]<=x)
			tut[i]=1;
	}

	if(tut[n]==tut[n-1] || tut[n]==tut[n+1])
	{
		return tut[n];
	}
	for(int i=1;i<n-1;i++)
	{
		if(tut[n-i]==tut[n-i-1])
			return tut[n-i];
		if(tut[n+i]==tut[n+i+1])
			return tut[n+i]; 
	}
	return tut[1];
}

ll bs()
{
	int l=1,r=m;
	while(l<r)
	{
		if(l==r-1)
		{
			if(check(l))
				r=l;

			break;
		}
		int mid=(l+r)/2;
		// cout<<mid<<sp<<check(mid)<<endl;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	return r;
}

int main()
{
	fast;
	cin>>n;
	m=n*2-1;
	fs(ar,m);
	cout<<bs();

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/