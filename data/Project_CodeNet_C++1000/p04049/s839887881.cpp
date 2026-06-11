#include<bits/stdc++.h>

using namespace std;

inline int read()
{
	int f = 1,x = 0;
	char ch;
	do
	{
		ch = getchar();
		if(ch == '-') f = -1;
	}while(ch < '0'||ch > '9');
	do
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}while(ch >= '0'&&ch <= '9');
	return f*x;
} 

const int MAXN = 2000 + 10;

int n,k;
int u[MAXN],v[MAXN];
vector<int>G[MAXN];
int dep[MAXN];
int ans,cnt;

inline void dfs(int x,int f)
{
	for(int i=0;i<G[x].size();i++)
	{
		int v = G[x][i];
		if(v == f) continue;
		dep[v] = dep[x] + 1;
		dfs(v,x);
	}
}

int main()
{
	n = read(),k = read();ans = 1<<30;
	for(int i=1;i<n;i++)
	{
		int a = read(),b = read();
		G[a].push_back(b);
		G[b].push_back(a);
		u[i] = a;v[i] = b;
	}
	if(k&1)
	{
		for(int i=1;i<n;i++)
		{
			memset(dep,0,sizeof(dep));
		    cnt = 0;
			dfs(u[i],v[i]);
			dfs(v[i],u[i]);
			for(int j=1;j<=n;j++) if(dep[j]>(k-1)/2) cnt++;	
			ans = min(ans ,cnt);
		}

	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cnt = 0;
			memset(dep,0,sizeof(dep));
			dfs(i,0);
			for(int j=1;j<=n;j++)
			{
				if(dep[j]>(k/2)) cnt++;
			} 
			ans = min(ans , cnt);
		}
	}
	cout << ans << endl;
}