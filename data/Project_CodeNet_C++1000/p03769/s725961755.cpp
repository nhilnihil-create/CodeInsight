#include<cstdio>
using namespace std;
typedef long long ll;
const int N=220;
int i,j,k,m,nm,ch,ff,l,r;
ll n;
int a[N],b[N];
void R(ll &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
int main() {
	R(n);nm=0;
	while (n>2) {
		if (n&1) a[++m]=1;
		else a[++m]=2;
		nm+=a[m];
		n=(n-a[m])>>1;
	}
	a[++m]=n;
	nm+=a[m];
	for (i=1;i<=nm;i++) b[i]=i;
	l=1;r=nm;
	j=nm+nm;
	for (i=1;i<=m;i++) {
		if (a[i]==1) b[j]=r--;
		else {
			b[j]=l++;
			b[j-1]=r--;
		}
		j-=a[i];
	}
	printf("%d\n",nm+nm);
	for (i=1;i<=nm+nm;i++) printf("%d ",b[i]);
	puts("");
}