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
#define ull unsigned long long int
using namespace std;

ll n,m,ar[N],sum,t,mark[N],vis[N][15];

pair<ii,int> p[N];

vector<int> v[N];

void f(int ind,int maxd,int d,int col)
{
	if(vis[ind][maxd-d])
		return;
	vis[ind][maxd-d]++;
	if(!mark[ind])
	mark[ind]=col;
	if(d==maxd)
		return;
	for(int i=0;i<v[ind].size();i++)
		f(v[ind][i],maxd,d+1,col);
}

int main()
{
	fast;
	cin>>n>>m;
	fo(i,1,m)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int q;

	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>p[i].fi.fi>>p[i].fi.se>>p[i].se;
	}
	for(int i=q;i>=1;i--)
		f(p[i].fi.fi,p[i].fi.se,0,p[i].se);
	for(int i=1;i<=n;i++)
	{
		cout<<mark[i]<<endl;
	}


}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/