#include <bits/stdc++.h>
using namespace std;

const int Maxn=100005;

vector<int> v[Maxn];
int n,f[Maxn],s[Maxn];


void dfs(int a,int p,int deep)
{
	f[a]=deep;
	for(int i=0;i<v[a].size();i++)
		if(v[a][i] != p)
			dfs(v[a][i],a,deep+1);
}
 

int main()
{
	int F=0,S=0;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(n,0,0);
	for(int i=1;i <= n;i++)
		s[i]=f[i];
	dfs(1,0,0);
	for(int i=1;i <= n;i++)
		if(f[i] <= s[i])
			F++;
		else
			S++;
	if(F>S)
		puts("Fennec");
	else
		puts("Snuke");
	return 0;
}