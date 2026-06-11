#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
const int N=100005;
int n,K,ans,tot,h[N],ne[N],to[N],dep[N],dis[N];
void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
void dfs(int x,int las) {
	dis[x]=dep[x];
	for(RI i=h[x];i;i=ne[i]) {
		dep[to[i]]=dep[x]+1,dfs(to[i],x);
		dis[x]=max(dis[x],dis[to[i]]);
	}
	if(las!=1&&x!=1&&dis[x]-dep[x]==K-1) ++ans,dis[x]=0;
}
int main()
{
	int x;
	n=read(),K=read();
	for(RI i=1;i<=n;++i) {
		x=read();
		if(i==1&&x!=1) x=1,++ans;
		if(i!=1) add(x,i);
	}
	dfs(1,0),printf("%d\n",ans);
	return 0;
}