#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int m,a,b,frst,cnt[100010];
vector<int> vct,v[100010];
void dfs(int n,int p)
{
	cnt[n]=1;
	vct.pb(n);
	if (n==m) frst=vct[(vct.size()+1)/2];
	for (int i=0;i<v[n].size();++i)
	{
		if (v[n][i]==p)continue;
		dfs(v[n][i],n);
		cnt[n]+=cnt[v[n][i]];
	}
	vct.pop_back();
}
int main()
{
	cin>>m;
	for (int i=0;i<m-1;++i)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	frst=-1;
	dfs(1,-1);
	bool win=cnt[frst]*2<m;
	if (win) cout<<"Fennec";
	else cout<<"Snuke";
    return 0;
}