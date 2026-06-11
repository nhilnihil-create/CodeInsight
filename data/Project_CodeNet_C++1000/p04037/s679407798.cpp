#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,i,j,l,r,a[N];
int main()
{
//	freopen("candy.in","r",stdin);
//	freopen("candy.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	rep(i,1,n)
	if (i==n+1 || a[i]<i) break; i--;
	r=a[i]+1-i;
	if (r%2==0) printf("First\n");
	else {
		for (j=i;j<=n && a[j]>=i;j++);
		l=j-i;
		if (l%2==0) printf("First\n");
		else printf("Second\n");
	}
	return 0;
}