#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll n;
	cin >> n;
	vector<vector<pair<ll,int>>> M(n);
	for(ll i = 0;i<n-1;i++)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		M[a].emplace_back(b,c);
		M[b].emplace_back(a,c);
	}
	ll q,k;
	cin >> q >> k;
	vector<ll> d(n,-1);
	k--;
	d[k] = 0;
	queue<ll> Q;
	Q.push(k);
	while(!Q.empty())
	{
		ll now = Q.front();
		Q.pop();
		for(auto i:M[now])
		{
			if(d[i.first]==-1)
			{
				d[i.first] = d[now]+i.second;
				Q.push(i.first);
			}
		}
	}
	while(q--)
	{
		ll x,y;
		cin >> x >> y;
		x--,y--;
		cout<<d[x]+d[y]<<endl;
	}

	return 0;
}
