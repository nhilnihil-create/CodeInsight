#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k,ans,dep[maxn],mx[maxn],V[maxn],X[maxn];
vector <int> mp[maxn];

inline void dfs(int u,int fa)
{
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(v==fa) continue;
		dep[v]=dep[u]+1; mx[v]=dep[v]; dfs(v,u);
		if(!V[v]) mx[u]=max(mx[u],mx[v]);
	}
	if(mx[u]-dep[u]==k-1&&!X[u]&&!V[u]) ans++,V[u]=1;
}

int main()
{
	n=read(); k=read(); X[1]=1;
	rep(i,1,n)
	{
		int x=read(); if(x==1) X[i]=1;
		if(i!=1) mp[i].pb(x),mp[x].pb(i);
		else if(x!=1) ans++;
	}
	dfs(1,0); cout<<ans<<endl;
	return 0;
}