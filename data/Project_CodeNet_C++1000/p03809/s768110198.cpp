#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100100;
int i,j,k,n,m,En,ch,ff,x,y,Fg;
int h[N],d[N],A[N];
ll f[N];
struct edge { int s,n;} E[N<<1];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x-=x;
}
void E_add(int x,int y) {
	d[x]++;d[y]++;
	E[++En].s=y;E[En].n=h[x];h[x]=En;
	E[++En].s=x;E[En].n=h[y];h[y]=En;
}
void dfs(int x,int F) {
	ll sum=0,ma=0;
	int fg=0;
	for (int k=h[x];k;k=E[k].n) if (E[k].s!=F) {
		fg=1;
		dfs(E[k].s,x);
		if (Fg) return;
		sum+=f[E[k].s];
		ma=max(ma,f[E[k].s]);
	}
	if (!fg) f[x]=A[x];
	else {
		f[x]=2*A[x]-sum;
		if (f[x]<0) { Fg=1;return;}
		if (ma*2-sum>f[x] || f[x]>sum) { Fg=1;return;}
	}
}
int main() {
	R(n);
	for (i=1;i<=n;i++) R(A[i]);
	for (i=1;i<n;i++) {
		R(x);R(y);
		E_add(x,y);
	}
	if (n==2) {
		if (A[1]==A[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for (i=1;i<=n;i++) if (d[i]!=1) break;
	dfs(i,0);
	if (Fg || f[i]) puts("NO");
	else puts("YES");
}