#include<bits/stdc++.h>
using namespace std;


int n, m, a, b, q, cor[100010][14], v[100010], d[100010], c[100010];

vector <int> e[100010];

void dfs(int st, int deep, int cl)
{
	if(deep == -1)
		return;
	if(cor[st][deep])
		return;
	cor[st][deep] = cl;
	for(int i = 0; i < e[st].size(); ++ i)
		dfs(e[st][i], deep-1, cl);
}

int main()
{
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1; i<=n; i++)
		e[i].push_back(i);
	cin>>q;
	for(int i=1; i<=q; i++)
		cin>>v[i]>>d[i]>>c[i];
	for(int i=q; i>=1; i--)
		dfs(v[i], d[i], c[i]);
	for(int i=1; i<=n; i++)
		cout<<cor[i][0]<<endl;
	return 0;
}