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

vector <int> mp[maxn],a1,a2;
int n,m,V[maxn];

inline void dfs1(int u)
{
	V[u]=1; a1.pb(u);
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(V[v]) continue;
		dfs1(v); break;
	}
}

inline void dfs2(int u)
{
	V[u]=1; a2.pb(u);
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(V[v]) continue;
		dfs2(v); break;
	}
}

int main()
{
	n=read(); m=read();
	rep(i,1,m)
	{
		int u=read(),v=read();
		mp[u].pb(v); mp[v].pb(u);
	}
	dfs1(1); dfs2(1); cout<<a1.size()+a2.size()-1<<endl;
	for(int i=a1.size()-1;i>=0;i--) printf("%d ",a1[i]);
	for(int i=1;i<a2.size();i++) printf("%d ",a2[i]);
	return 0;
}