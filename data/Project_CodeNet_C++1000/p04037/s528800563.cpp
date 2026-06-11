#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100100;
int i,j,k,n,ch,ff;
int a[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
int main() {
	R(n);
	for (i=1;i<=n;i++) R(a[i]);
	sort(a+1,a+n+1);
	for (i=1;i+i<=n;i++) swap(a[i],a[n-i+1]);
	int x=1;
	while (a[x+1]>=x+1) x++;
	int u=a[x]-x+1,r=1;
	while (x<=a[x+r]) r++;
	if (!(u&1) || !(r&1)) puts("First");
	else puts("Second");
}