#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<pair<ll,ll>> G[100000];
ll D[100000];


void dfs(int idx,int pair = -1)
{
	for(auto i:G[idx])
	{
		if(pair==i.first)continue;
		D[i.first] += D[idx] + i.second;
		dfs(i.first,idx);
	}
}

int main()
{
	cin >> n;
	for(int i = 0;i<n-1;i++)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		G[a].emplace_back(b,c);
		G[b].emplace_back(a,c);
	}
	ll q,k;
	cin >> q >> k;
	k--;
	dfs(k);
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		x--;y--;
		cout<<D[x]+D[y]<<endl;
	}
	

}