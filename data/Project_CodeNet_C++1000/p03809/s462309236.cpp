#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n,a[N],fir[N],to[N<<1],nxt[N<<1],c[N<<1],tot(1),d[N],root,s[N],ok(0);

template <class Aqua>
inline void read(Aqua &s){
	s=0; char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) s=s*10+c-'0',c=getchar();
}

inline void add(int u,int v){
	to[++tot]=v; nxt[tot]=fir[u]; fir[u]=tot; d[v]++;
}

void dfs(int x,int fa){
	if (ok) return;
	int fl=0; s[x]=0;
	for (int i=fir[x];i && !ok;i=nxt[i])
		if (to[i]!=fa){
			fl=1;
			dfs(to[i],x);
			c[i]=c[i^1]=2*a[to[i]]-s[to[i]];
			s[x]+=c[i];
			if (c[i]<0)
				ok=1;
		}
	if (!fl)
		s[x]=a[x];
	if (!fa)
		if (s[x]!=2*a[x])
			ok=1;
}

int main(){
	read(n);
	for (int i=1;i<=n;i++)
		read(a[i]);
	int u,v;
	for (int i=1;i<n;i++){
		read(u),read(v);
		add(u,v),add(v,u);
	}
	if (n==2){
		if (a[1]==a[2])
			puts("YES");
		else
			puts("NO");
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (d[i]!=1)
			root=i;
	dfs(root,0);
	if (ok){
		puts("NO"); return 0;
	}
	for (int i=1;i<=n && !ok;i++)
		if (d[i]!=1){
			int s=0;
			for (int j=fir[i];j;j=nxt[j])
				s+=c[j];
			if (s&1)
				ok=1;
			for (int j=fir[i];j;j=nxt[j])
				if (c[j]>s/2)
					ok=1;
		}
	if (ok)
		puts("NO");
	else
		puts("YES");
	return 0;
}