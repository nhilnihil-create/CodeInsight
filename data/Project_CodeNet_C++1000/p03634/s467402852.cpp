/**
 * author:    Ziel
 * created:   22.04.2020 20:29:29
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,z,m,k,to,len,d[100100];
set<pair<ll,ll>>q;
vector<pair<ll,ll>>g[100100];
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<n;i++)
		scanf("%lld%lld%lld",&x,&y,&z),g[x].push_back({y,z}),g[y].push_back({x,z});
	scanf("%lld%lld",&m,&k);
	q.insert({0,k});
	for(ll i=1;i<=n;i++)
		d[i]=2000000000000000009;
	d[k]=0;
	while(q.size())
	{
		int v=q.begin()->second;
		q.erase(q.begin());
		for(auto edge:g[v])
		{
			to=edge.first,len=edge.second;
			if(d[to]>d[v]+len)
			{
				q.erase({d[to], to});
				d[to]=d[v]+len;
				q.insert({d[to], to});
			}
		}
	}
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",d[x]+d[y]);
	}
	return 0;
}

/*
	Raise your standard.
*/