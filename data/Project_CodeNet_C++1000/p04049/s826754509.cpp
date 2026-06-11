#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k,dep[maxn],vis[maxn],cnt[maxn],U[maxn],V[maxn];
vector <int> mp[maxn];

inline void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(vis[v]) continue;
		dep[v]=dep[u]+1; dfs(v);
	}
}

int main()
{
	n=read(); k=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(); U[i]=u; V[i]=v;
		mp[u].push_back(v); mp[v].push_back(u);
	}
	int ans=0;
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			dep[i]=1; dfs(i);
			for(int j=1;j<=n;j++) vis[j]=0;
			for(int j=1;j<=2000;j++) cnt[j]=0;
			for(int j=1;j<=n;j++) cnt[dep[j]]++;
			
			int x=k/2+1,tmp=0;
			for(int j=1;j<=x;j++) tmp+=cnt[j]; ans=max(ans,tmp);
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=2000;j++) cnt[j]=0;
			for(int j=1;j<=n;j++) vis[j]=0,dep[j]=0;
			dep[U[i]]=1; vis[V[i]]=1; dfs(U[i]);
			for(int j=1;j<=n;j++) cnt[dep[j]]++;
			
			for(int j=1;j<=n;j++) vis[j]=0,dep[j]=0;
			dep[V[i]]=1; vis[U[i]]=1; dfs(V[i]);
			for(int j=1;j<=n;j++) cnt[dep[j]]++;
			
			int x=(k+1)/2,tmp=0;
			for(int j=1;j<=x;j++) tmp+=cnt[j]; ans=max(ans,tmp);
		}
	}
	cout<<n-ans<<endl;
	return 0;
}