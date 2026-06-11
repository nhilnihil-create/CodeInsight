#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;
typedef long long LL;

int a[maxn];
LL sum[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
		scanf("%d",&a[i]),sum[i] = sum[i - 1] + a[i];
	LL ans = 1e18;
	for(int div = 1; div < n; ++div){
		LL A = sum[div],B = sum[n] - sum[div];
		ans = min(ans,llabs(A - B));
	}
	printf("%lld\n",ans);
	return 0;
}
