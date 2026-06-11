#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,in[maxn],head[maxn],pos;
int tot,nxt[maxn*2],to[maxn*2];
ll a[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
ll f(ll x,ll y) {
	if (x%2==y%2) return x;
	return x-1;
}
ll dfs(int u,int p) {
	ll res=0,x=0,y=0,tmp,z; vector<int> d;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v!=p) tmp=dfs(v,u),d.push_back(tmp),res+=tmp;
	}
	//printf("%d %lld\n",u,res);
	if (in[u]==1) return a[u];
	tmp=res-a[u];
	if (res<a[u]||a[u]<tmp) { printf("NO\n"); exit(0); }
	sort(d.begin(),d.end());
	for (int i=0;i<d.size();i++) {
		if (d[i]>x) z=f(x,y);
		else z=f(d[i],y);
		x+=d[i]; y=d[i]-z;
		//printf("%lld %lld %lld\n",x,y,z);
	}
	if ((res-y)/2<tmp) { printf("NO\n"); exit(0); }
	return a[u]-tmp;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<n;i++) {
		read(x); read(y);
		in[x]++; in[y]++;
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++) if (in[i]!=1) pos=i;
	if (!pos) {
		if (a[1]==a[2]) printf("YES\n");
		else printf("NO\n"); return 0;
	}
	if (dfs(pos,0)==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}