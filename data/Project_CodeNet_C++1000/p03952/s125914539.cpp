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

ll n,m,ar[N],sum,t;

vector<int> v;

int main()
{
	fast;
	cin>>n>>m;
	n=n*2-1;
	if(m==1 || m==n)
		return cout<<"No",0;
	cout<<"Yes"<<endl;
	if(n==3)
	{
		for(int i=1;i<=n;i++)
			cout<<i<<endl;
		return 0;
	}
	int a=m-1;
	int b=m+1;
	int c=b+1;
	if(c>n)
	{
		swap(a,b);
		c=b-1;
	}
	for(int i=1;i<=n;i++)
		if(i!=a && i!=b && i!=c && i!=m)
			v.pb(i);
	for(int i=1;i<=(n+1)/2-3;i++)
	{
		cout<<v[v.size()-1]<<endl;
		v.ppb();
	}
	cout<<c<<endl<<a<<endl<<m<<endl<<b<<endl;
	for(int i=(n+1)/2+2;i<=n;i++)
	{

		cout<<v[v.size()-1]<<endl;
		v.ppb();
	}

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/