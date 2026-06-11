#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<ll> v[100001];
ll vis[100001]={0};
ll val[100001]={0};
void dfs(ll node)
{
	vis[node]=1;
	for(ll i=0;i<v[node].size();i++)
	{
		if(vis[v[node][i]]==0)
		{
			dfs(v[node][i]);
			val[node]^=(val[v[node][i]]+1);
		}
	}
	return;
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	if(val[1]!=0)
	cout<<"Alice"<<endl;
	else
	cout<<"Bob"<<endl;
}