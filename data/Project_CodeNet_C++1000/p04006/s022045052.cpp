#include <bits/stdc++.h>
#define N 2005
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

ll n,m,ar[N],sum=0,t,tut[N];



int main()
{
	fast;
	cin>>n>>m;
	fo(i,0,n-1)
		cin>>ar[i];
	for(int i=0;i<n;i++)
		tut[i]=ar[i],sum+=ar[i];
	for(ll i=1;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			ll ind=j-i;
			ind+=n;
			ind%=n;
			tut[j]=min(tut[j],ar[(n-i+j)%n]);
		}

		ll top=0;
		for(ll j=0;j<n;j++)
			top+=tut[j];
		// if(top==20)
		// 	cout<<i<<endl;
		sum=min(sum,i*m+top);

	}
	cout<<sum<<endl;
}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/