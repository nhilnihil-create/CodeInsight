#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

#define eps 1e-12
#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define bgn begin
#define ll long long
#define ld long double
#define ull unsigned long long
#define ii pair<ll,ll>






#define typ ll


const int N=310;
int prnt[N];
typ d[N];
bool vst[N];
vector<pair<int,int>>adj[N];
priority_queue<pair<typ,int>,vector<pair<typ,int>>,greater<pair<typ,int>>>q;
pair<typ,int>p;

void dijkstra(int s,int n)
{
	for(int i=1;i<=n;i++)
	{
		d[i]=-1;
		vst[i]=false;
	}
	d[s]=0;
	p.first=d[s];
	p.second=s;
	q.push(p);
	while(!q.empty())
	{
		p=q.top();
		int u=p.second;
		q.pop();
		if(vst[u])continue;
		vst[u]=true;
		for(int i=0,v,w;i<adj[u].size();i++)
		{
			v=adj[u][i].first;
			w=adj[u][i].second;
			if(d[v]==-1 || d[u]+w<d[v])
			{
				prnt[v]=u;
				d[v]=d[u]+w;
				p.first=d[v];
				p.second=v;
				q.push(p);
			}
		}
	}
}









ll n,u,v,w;
ll res;
vector<pair<int,pair<int,int>>>e;









void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)cin>>w;
		for(int j=i+1;j<=n;j++)
		{
			cin>>w;
			e.pb(mp(w,mp(i,j)));
		}
	}
	sort(e.begin(),e.end());
	res=0;
	for(int i=0;i<e.size();i++)
	{
		w=e[i].first;
		u=e[i].second.first;
		v=e[i].second.second;
		dijkstra(u,n);
		if(d[v]==-1||d[v]>w)
		{
			adj[u].pb(mp(v,w));
			adj[v].pb(mp(u,w));
			res+=w;
		}
		else if(d[v]<w)
		{
			cout<<"-1\n";
			return;
		}
	}
	cout<<res<<"\n";
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef localProject
	freopen("in.txt","r",stdin);
#endif
	solve();
	return 0;
}