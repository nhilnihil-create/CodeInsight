#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<ar<ll,3> >v;
	for(ll i=0,j,k,c; i<m; i++)
	{
		cin>>j>>k>>c, --j,--k;
		c = -c;
		v.push_back({j,k,c});
	}
	ll dist[n];
	fill(dist,dist+n,(ll)(1e18));
	dist[0]=0;
	for(int i = 0; i<n-1; i++)
	{
		for(auto it:v)
		{
			if(dist[it[0]]==(ll)1e18)
				continue;
			dist[it[1]] = min(dist[it[1]],dist[it[0]]+ it[2]);
		}
	}

	bool vis[n] = {0};
	for(auto it:v)
	{
		if(dist[it[0]]== (ll)1e18)
			continue;
		if(dist[it[0]]+it[2]<dist[it[1]])
			vis[it[1]] = 1;
		if(vis[it[0]])
			vis[it[1]]=1;
	}
	if(vis[n-1])
		cout<<"inf"<<endl;
	else
		cout<<(-dist[n-1])<<endl;
	return 0;
}