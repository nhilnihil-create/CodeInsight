/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,x;
vector <int> g[100010];

int dfs(int pos)
{
	vector <int> v;
	v.clear();
	rep(i,g[pos].size()) v.pb(dfs(g[pos][i]));
	if(v.size()==0) return 0;
	sort(v.begin(),v.end());
	int ret=0;
	for(int i=v.size()-1,j=1;i>=0;i--,j++) ret=max(ret,v[i]+j);
	return ret;
}

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].pb(i);
	}
	cout<<dfs(1)<<endl;
	return 0;
}