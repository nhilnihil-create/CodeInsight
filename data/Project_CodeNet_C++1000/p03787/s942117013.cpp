#include <bits/stdc++.h>
#define N 200010
#define ll long long
using namespace std;
int n,m,fir[N],nxt[N<<1],to[N<<1],tot(1),vis[N],col[N],num,tag;

template <class Aqua>
inline void read(Aqua &s){
	s=0; char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) s=s*10+c-'0',c=getchar();
}

inline void add(int u,int v){
	to[++tot]=v; nxt[tot]=fir[u]; fir[u]=tot;
}

void dfs(int x){
	vis[x]=1; num++;
	for (int i=fir[x];i;i=nxt[i])
		if (!vis[to[i]])
			col[to[i]]=col[x]^1,dfs(to[i]);
		else
			if (col[to[i]]==col[x]) tag=1;
}

int main(){
	read(n),read(m);
	int u,v;
	for (int i=1;i<=m;i++){
		read(u),read(v);
		add(u,v),add(v,u);
	}
	ll x(0),y(0),z(0);
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			num=col[i]=tag=0;
			dfs(i);
			if (num==1) x++;
			else
				if (tag) y++;
				else z++;
		}
//	printf("%lld %lld %lld\n",x,y,z);
	ll ans=2*x*n-x*x+y*y+2*y*z+2*z*z;
	printf("%lld\n",ans);
	return 0;
}