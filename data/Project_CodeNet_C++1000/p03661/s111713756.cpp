#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; scanf("%d", &n);
	i64 sum = 0;
	std::vector<i64> a(n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		
		sum += a[i];
	}
	
	i64 tmp = 0, ans = 1LL << 60;
	for(int i = 0; i < n - 1; i++) {
		tmp += a[i];
		sum -= a[i];
		
		ans = std::min(ans, std::abs(tmp - sum));
	}
	printf("%lld\n", ans);
	return 0;
}
