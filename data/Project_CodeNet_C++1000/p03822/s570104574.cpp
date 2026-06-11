#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
#define maxn 100005
inline ll read()
{
	ll x=0,w=0;char ch=getchar();
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,size[maxn];
struct op{int x,y;};
inline bool com(op x,op y){return x.y>y.y;}
vector<op>G[maxn];
inline void dfs(int u)
{
    reg int i,sz=G[u].size();
    for(i=0;i<sz;++i)
    {
        dfs(G[u][i].x);
        G[u][i].y=size[G[u][i].x];
    }
    sort(G[u].begin(),G[u].end(),com);
    for(i=sz-1;i>=0;--i)
        size[u]=max(size[u],G[u][i].y+i+1);
}
int main()
{
    n=read();reg int i,x;
    for(i=2;i<=n;++i)
        x=read(),G[x].push_back(op{i,0});
    dfs(1);cout<<size[1]<<"\n";
	return 0;
}
