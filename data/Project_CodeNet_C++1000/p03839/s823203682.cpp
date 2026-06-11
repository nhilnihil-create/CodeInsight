#include <bits/stdc++.h>
using namespace std;

int a[100010];
long long sum[100010];
long long sum1[100010];

int main(){
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		sum1[i] = sum1[i - 1] + (a[i] < 0 ? 0 : a[i]); 
	}
	long long ans = 0;
	for (int i = 1; i <= n - k + 1; i++){
		int l = i, r = i + k - 1;
		long long val = sum[r] - sum[l - 1];
		ans = max(ans, sum1[l - 1] + sum1[n] - sum1[r] + (val < 0 ? 0 : val));
	}
	printf("%lld\n", ans);
	return 0;
}
