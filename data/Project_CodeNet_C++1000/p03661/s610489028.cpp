#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long sum, s, r = 1e18;
int n, w[201000];
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		sum += w[i];
	}
	for (i = 1; i < n; i++) {
		s += w[i];
		r = min(r, abs(s * 2 - sum));
	}
	printf("%lld\n", r);
}