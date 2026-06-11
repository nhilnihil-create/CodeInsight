#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100100;
int i,j,k,n,m,ch,ff;
ll K;
int x[N],a[N],p[N],ans[N],tmp[N];
ll Ans[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void R(ll &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void W(ll x) {
	if (x<0) putchar('-'),x=-x;
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
void work(int *A,int *B,int *C) {
	int i;
	for (i=1;i<n;i++) tmp[i]=A[B[i]];
	for (i=1;i<n;i++) C[i]=tmp[i];
}
int main() {
	R(n);
	for (i=1;i<=n;i++) R(x[i]);
	R(m);R(K);
	for (i=1;i<n;i++) ans[i]=p[i]=i;
	for (i=1;i<=m;i++) {
		R(a[i]);
		swap(p[a[i]-1],p[a[i]]);
	}
	for (;K;K>>=1,work(p,p,p))
		if (K&1) work(ans,p,ans);
	for (i=1;i<n;i++) Ans[i]=x[ans[i]+1]-x[ans[i]];
	Ans[0]=x[1];
	for (i=1;i<n;i++) Ans[i]+=Ans[i-1];
	for (i=0;i<n;i++) W(Ans[i]),puts("");
}