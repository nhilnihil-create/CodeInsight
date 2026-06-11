#include"bits/stdc++.h"
#define F(i,j,n) for(register int i=j;i<=n;i++)
#define D(i,j,n) for(register int i=j;i>=n;i--)
#define ll long long
#define N 200010
using namespace std;
namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,c;int f;
	char gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++;
		}
		return*iS++;
	}
	template<class I>void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
};
using io::gi;
using io::gc;
int head[N],nxt[N<<1],to[N<<1],tot,n,f[N];
void adli(int u,int v){
	++tot;nxt[tot]=head[u];head[u]=tot;to[tot]=v;
	++tot;nxt[tot]=head[v];head[v]=tot;to[tot]=u;
}
void dfs(int u,int fa){
	int i,v;
	for(i=head[u];i;i=nxt[i]){
		v=to[i];if(v==fa)continue;
		dfs(v,u);f[u]^=f[v]+1;
	}
}
int main(){
	int u,v;
	gi(n);F(i,2,n)gi(u),gi(v),adli(u,v);
	dfs(1,0);puts(f[1]?"Alice":"Bob");
	return 0;
}
