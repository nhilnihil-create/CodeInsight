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

int col[maxn],md[maxn],V[maxn],d[maxn],c[maxn],n,m;
vector <int> mp[maxn];

inline void wk(int u,int x,int C)
{
	if(x<=md[u]) return;
	md[u]=x; if(!col[u]) col[u]=C;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		wk(v,x-1,C);
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
	int q=read();
	rep(i,1,n) md[i]=-1;
	rep(i,1,q) V[i]=read(),d[i]=read(),c[i]=read();
	per(i,q,1) wk(V[i],d[i],c[i]);
	rep(i,1,n) printf("%d\n",col[i]);
	return 0;
}