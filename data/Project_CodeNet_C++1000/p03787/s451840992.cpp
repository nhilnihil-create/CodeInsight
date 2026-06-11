#include<cstdio>
using namespace std;
typedef long long ll;
const int N=100100,M=400400;
int i,j,k,n,m,ch,ff,x,y,fg,n1,n2,n3,En;
ll ans;
int h[N],z[N];
struct edge { int s,n;} E[M];
void R(int &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void W(ll x) {
	if (x<0) putchar('-'),x=-x;
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
void E_add(int x,int y) {
	E[++En].s=y;E[En].n=h[x];h[x]=En;
	E[++En].s=x;E[En].n=h[y];h[y]=En;
}
void dfs(int x,int y) {
	z[x]=y;
	for (int k=h[x];k;k=E[k].n) {
		if (!z[E[k].s]) dfs(E[k].s,3-y);
		else {
			if (z[E[k].s]!=3-y) fg=0;
		}
	}
}
int main() {
	R(n);R(m);
	for (i=1;i<=m;i++) {
		R(x);R(y);
		E_add(x,y);
	}
	for (i=1;i<=n;i++) if (!z[i]) {
		if (!h[i]) n1++;
		else {
			fg=1;
			dfs(i,1);
			n2+=fg;
			n3+=fg^1;
		}
	}
	ans=(ll) n1*(2*n-n1)+2ll*n2*n2+(ll) n3*n3+2ll*n2*n3;
	W(ans);puts("");
}