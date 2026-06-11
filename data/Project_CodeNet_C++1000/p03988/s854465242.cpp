#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,i,d,a[N],cnt[N];
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	if (a[n-1]!=a[n]) {
		printf("Impossible\n");
		return 0;
	}
	cnt[a[n]]-=2;
	rep(i,1,a[n]-1)
	{
		d=max(i,a[n]-i);
		if (cnt[d]<1) {
			printf("Impossible\n");
			return 0;
		}
		cnt[d]--;
	}
	rep(i,1,(a[n]+1)/2)
		if (cnt[i]) {
			printf("Impossible\n");
			return 0;
		}
	printf("Possible\n");
	return 0;
}