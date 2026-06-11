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
	int n;
	cin>>n;
	vector<ar<ll,2> > v[n];
	for(int i = 0; i<n-1; i++)
	{
		int j,k,c;
		cin>>j>>k>>c, --j,--k;
		v[j].push_back({k,c});
		v[k].push_back({j,c});
	}
	int q,k;
	cin>>q>>k, --k;
	ll dist[n];
	memset(dist,0x3f, sizeof(dist));
	dist[k] = 0;
	priority_queue<ar<ll,2> , vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
	pq.push({0,k});
	while(!pq.empty())
	{
		auto y = pq.top();
		pq.pop();
		for(auto it:v[y[1]])
		{
			if(dist[it[0]]>dist[y[1]]+it[1])
			{
				dist[it[0]] = dist[y[1]] + it[1];
				pq.push({dist[it[0]],it[0]});
			}
		}
	}
	// for(auto it:dist)
	// 	cout<<it<<endl;
	while(q--)
	{
		int x,y;
		cin>>x>>y, --x, --y;
		cout<<dist[x]+dist[y]<<endl;
	}
	return 0;
}