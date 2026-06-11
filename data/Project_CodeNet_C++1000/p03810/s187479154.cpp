#include<cstdio>
using namespace std;
const int N=100100;
int i,j,k,n,ch,ff,sum,Fg;
int a[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
int gcd(int a,int b) {
	if (!b) return a;
	return gcd(b,a%b);
}
int main() {
	R(n);
	for (i=1;i<=n;i++) R(a[i]),sum^=a[i]&1;
	if (!(n&1)) {
		if (sum&1) puts("First");
		else puts("Second");
		return 0;
	}
	if (!(sum&1)) return puts("First"),0;
	for (i=0;;i^=1) {
		k=-1;
		for (j=1;j<=n;j++) if (a[j]&1) {
			if (k!=-1 || a[j]==1) { k=-1;break;}
			k=j;
		}
		if (k==-1) {
			if (i&1) puts("First");
			else puts("Second");
			return 0;
		}
		a[k]--;
		int g=a[1];
		for (j=2;j<=n;j++) g=gcd(g,a[j]);
		for (j=1;j<=n;j++) a[j]/=g;
		k=0;
		for (j=1;j<=n;j++) k^=a[j]&1;
		if (!k) {
			if (i&1) puts("First");
			else puts("Second");
			return 0;
		}
	}
}