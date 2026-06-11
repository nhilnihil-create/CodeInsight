#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

ll dist[int(1e5)+2];
void dfs(vector<ar<ll,2>> *v, int parent,int vertex, ll c)
{
	dist[vertex] = c;
	for(auto it:v[vertex])
		if(it[0]!=parent)
			dfs(v,vertex,it[0],dist[vertex]+it[1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dist,0x3f, sizeof(dist));
	int n;
	cin>>n;
	vector<ar<ll,2> > v[n];
	for(int i = 0,j,k,c; i<n-1; i++)
	{
		cin>>j>>k>>c, --j, --k;
		v[j].push_back({k,c});
		v[k].push_back({j,c});
	}
	int q,k;
	cin>>q>>k, --k;
	dist[k] = 0;
	dfs(v,-1,k,0);
	while(q--)
	{
		int x,y;
		cin>>x>>y, --x, --y;
		cout<<dist[x]+dist[y]<<"\n";
	}
	return 0;
}