#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
long long a[300005];
int main() {
	scanf("%d",&n);
	for(int i=1; i<=3*n; ++i)
		scanf("%lld",a+i);
	sort(a+1,a+3*n+1);
	long long ans=0;
	for(int i=3*n-1; i>=n+1; i-=2)
		ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}