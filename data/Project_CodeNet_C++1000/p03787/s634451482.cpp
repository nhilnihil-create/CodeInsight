#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vector<ll> a;
vector<ll> b;
int cc;

int col[100001];
vi adj[100001];
bool dfs(int u, int c)
{
	col[u]=c;
	cc++;
	bool pos=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(col[v]==-1)
		{
			pos&=dfs(v,c^1);
		}
		else if((c^1)!=col[v])
		{
			pos=false;
		}
	}
	return pos;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(col,-1,sizeof(col));
	for(int i=0;i<n;i++)
	{
		if(col[i]==-1)
		{
			cc=0;
			bool tmp = dfs(i,0);
			if(tmp)
			{
				a.pb(cc);
			}
			else
			{
				b.pb(cc);
			}
		}
	}
	//a = bipartite
	//b = non-bipartite
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll cnt1 = 0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==1) cnt1++;
	}
	ll ans=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==1) ans++;
		else ans+=2;
	}
	for(int i=0;i<b.size();i++)
	{
		ans++;
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=1) ans+=cnt1*a[i]*2;
	}
	for(int i=0;i<b.size();i++)
	{
		ans+=cnt1*b[i]*2;
	}
	ans+=cnt1*(cnt1-1);
	ans+=(int(a.size())-cnt1)*ll(b.size())*2;
	ans+=ll(b.size())*(ll(b.size())-1);
	ans+=(ll(a.size())-cnt1)*(ll(a.size())-cnt1-1)*2;
	cout<<ans<<'\n';
}
