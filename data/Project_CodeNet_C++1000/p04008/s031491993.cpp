#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100100;
int i,j,k,n,m,ch,ff,En,ans;
int a[N],f[N],h[N];
struct edge { int s,n;} E[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void E_add(int x,int y) {
	E[++En].s=y;E[En].n=h[x];h[x]=En;
}
void dfs(int x) {
	f[x]=1;
	for (int k=h[x];k;k=E[k].n) {
		dfs(E[k].s);
		f[x]=max(f[x],f[E[k].s]+1);
	}
	if (a[x]!=1 && f[x]>=m) f[x]=0,ans++;
}
int main() {
	R(n);R(m);
	for (i=1;i<=n;i++) R(a[i]);
	for (i=2;i<=n;i++) E_add(a[i],i);
	if (a[1]!=1) ans++;
	a[1]=1;
	dfs(1);
	printf("%d\n",ans);
}