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

ll n,m,ar[N],sum,t,pref[N],mk,tut;

vector<ll> ans;


int main()
{
	fast;
	cin>>n>>m;
	fs(ar,n);
	ll l=1,r=n;
	for(int i=1;i<=n;i++)
		if(ar[i]+ar[i+1]>mk)
			mk=ar[i]+ar[i+1],tut=i;
	if(mk<m)
		return cout<<"Impossible",0;;
	cout<<"Possible"<<endl;
	for(int i=1;i<tut;i++)
		cout<<i<<endl;
	for(int i=n-1;i>tut;i--)
		cout<<i<<endl;
	cout<<tut<<endl;


}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/