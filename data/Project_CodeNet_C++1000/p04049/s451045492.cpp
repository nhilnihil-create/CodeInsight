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

ll n,m,ar[N],sum=INT_MAX,t,mk,top,k;

vector<int> v[N];

ll f(int ind,int back,int len)
{
	if(len>k/2)
		top++;
	// if(len==k/2)
	// {
	// 	if(ind!=back)
	// 	mk=max(mk,(ll)v[ind].size()-1ll);
	// 	else
	// 		mk=max(mk,(ll)v[ind].size());
	// }
	ll tp=0;
	if(len==k/2+1)
		tp++;
	for(int i=0;i<v[ind].size();i++)
	{
		int x=v[ind][i];
		ll y=0;
		if(x!=back)
			y=f(x,ind,len+1);
		tp+=y;
		if(ind==back)
			mk=max(mk,y);
	}
	return tp;
}

int main()
{
	fast;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	if(k==1)
		return cout<<n-2,0;
	for(int h=1;h<=n;h++)
	{
		mk=0;
		top=0;
		int ind=h;
		f(ind,ind,0);
		// cout<<top<<sp<<mk<<endl;
		if(k%2==1)
			top-=mk;
		sum=min(sum,top);
		// if(top==5)
		// 	cout<<h<<sp<<mk<<endl;

	}
	cout<<sum<<endl;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/