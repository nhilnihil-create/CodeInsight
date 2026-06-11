#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 7;

LL sum[N], a[N], b[N], c[N];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), b[i] = b[i - 1] + max(a[i], 0LL), sum[i] = sum[i - 1] + a[i];
	for (int i = n; i >= 1; i--) c[i] = c[i + 1] + max(a[i], 0LL);
	LL ans = 0;
	for (int i = 1; i <= n - k + 1; i++){
		ans = max(ans, max(0LL, sum[i + k - 1] - sum[i - 1]) + b[i - 1] + c[i + k]);
	}
	printf("%lld", ans);
	return 0;
}