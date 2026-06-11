#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
const int N=2005,inf=0x3f3f3f3f;
int u[N],v[N],h[N],ne[N<<1],to[N<<1],dep[N];
int n,tot,ans,js,K;
void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
void dfs(int x,int las) {
	for(RI i=h[x];i;i=ne[i])
		if(to[i]!=las) dep[to[i]]=dep[x]+1,dfs(to[i],x);
}
int main()
{
	n=read(),K=read();
	for(RI i=1;i<n;++i)
		u[i]=read(),v[i]=read(),add(u[i],v[i]),add(v[i],u[i]);
	ans=inf;
	if(K&1) {
		for(RI i=1;i<n;++i) {
			dep[u[i]]=dep[v[i]]=0,dfs(u[i],v[i]),dfs(v[i],u[i]),js=0;
			for(RI j=1;j<=n;++j) if(dep[j]>K/2) ++js;
			ans=min(ans,js);
		}
	}
	else {
		for(RI i=1;i<=n;++i) {
			dep[i]=0,dfs(i,0),js=0;
			for(RI j=1;j<=n;++j) if(dep[j]>K/2) ++js;
			ans=min(ans,js);
		}
	}
	printf("%d\n",ans);
	return 0;
}