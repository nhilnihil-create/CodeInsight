#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=1e5+50;
int n,rt,a[N]; LL f[N];
vector <int> edge[N];
inline void dfs(int x,int fa) {
	if(edge[x].size()==1) {f[x]=a[x]; return;}
	LL sum=0;
	for(int e=edge[x].size()-1;e>=0;e--) {
		int v=edge[x][e]; if(v==fa) continue;
		dfs(v,x); sum+=f[v];
		if(f[v]>a[x]) {puts("NO"); exit(0);}
	}
	if(sum<a[x] || sum-a[x]>a[x]) {puts("NO"); exit(0);}
	f[x]=a[x]-(sum-a[x]);
}

int main() {
	n=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	if(n==2) {puts((a[1]==a[2]) ? "YES" : "NO"); return 0;}
	for(int i=1;i<n;i++) {
		int x=rd(), y=rd();
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	while(edge[rt].size()<=1) ++rt;
	dfs(rt,0); puts(f[rt] ? "NO" : "YES");
}