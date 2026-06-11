#include<stdio.h>
#include<vector>
#include<algorithm>
using lint = long long;
using std::pair;
using std::vector;
using pll = pair<lint, lint>;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<pll> vec;
	for (int i = 0; i < n; i++) {
		lint a, b;
		scanf("%lld%lld", &a, &b);
		vec.push_back({ a,b });
		
	}
	lint ans = 0;
	for (pll p : vec) {
		if ((p.first|k) == k) {
			ans += p.second;
		}
	}
	for (int i = 0; i <= 30; i++) {
		if (k&(1 << i)) {
			int q = (1 << i) - 1;
			int tmp = (k | q) ^ (1<<i);
			lint sum = 0;
			for (pll p : vec) {
				if ((p.first|tmp) == tmp) {
					sum += p.second;
				}
			}
			ans = std::max(ans, sum);
		}
	}
	printf("%lld", ans);

}