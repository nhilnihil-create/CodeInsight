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

lli p[N];

// bool cmp<

int main()
{
	fast;
	cin>>n;
	fo(i,1,n)
	cin>>p[i].fi,p[i].se=i;
	p[0].fi=-1;
	sort(p+1,p+n+1);
	int cnt=0;

	fo(i,1,n)
	{
		if(p[i].fi!=p[i-1].fi)
			cnt++;
		ar[p[i].se]=cnt;
	}

	fo(i,2,n)
	{
		if(ar[i]%2)
			sum++;
		i++;
	}
	cout<<sum<<endl;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/