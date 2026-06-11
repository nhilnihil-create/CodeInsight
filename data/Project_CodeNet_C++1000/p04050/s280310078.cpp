#include <cstdio>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,m,i,j,odd,l,c[N],a[N],b[N];
int main()
{
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m) {
		scanf("%d",&a[i]);
		if (a[i]%2==1) odd++,c[odd]=a[i];
	}
	if (odd>=3) printf("Impossible\n");
	else if (odd==0 && m==1) {
		b[++l]=1; b[++l]=n/2-1; b[++l]=n/2;
		if (a[1]==2) b[--l]=1;
		printf("%d\n",a[1]);
		printf("%d\n",l);
		rep(i,1,l) printf("%d ",b[i]); printf("\n");
	}
	else {
		if (odd>=1) rep(i,1,c[1]/2+1) b[++l]=2;
		rep(i,1,m)
		if (a[i]%2==0)	b[++l]=a[i];
		rep(i,1,c[2]/2) b[++l]=2;
		if (odd==1) b[l]--;
		if (odd==0) b[1]++,b[l]--;
		if (odd>=1) printf("%d ",c[1]); rep(i,1,m) if (a[i]%2==0) printf("%d ",a[i]);
		if (odd>=2) printf("%d ",c[2]); printf("\n");
		printf("%d\n",l);
		rep(i,1,l) printf("%d ",b[i]); printf("\n");
	}
	return 0;
}