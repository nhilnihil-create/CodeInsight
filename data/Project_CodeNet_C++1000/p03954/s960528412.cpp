#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
const int mxn=200010;
int n,m,a[mxn];
bool check(int x){
	int d0=n,d1=n;
	for (int i=2;i<=m;++i){
		if (a[i]<=x&&a[i-1]<=x) d0=m-i;
		if (a[i]>x&&a[i-1]>x) d1=m-i;
	}
	for (int i=m;i<n;++i){
		if (a[i]<=x&&a[i+1]<=x) d0=min(d0,i-m);
		if (a[i]>x&&a[i+1]>x) d1=min(d1,i-m);
	}
	return d0<d1||(d0==d1&&x==m);
}
int main()
{
	scanf("%d",&m);
	n=m*2-1;
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	int l=1,r=n;
	for (;l<=r;)
		if (check(mid)) r=mid-1;
		else l=mid+1;
	printf("%d\n",l);
	return 0;
}