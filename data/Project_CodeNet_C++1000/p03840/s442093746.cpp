#include <cstdio>
long long a, b, c, d, ans, t;
int main() {
	scanf("%lld%lld%*lld%lld%lld", &a, &b, &c, &d);
	t = a%2 + c%2 + d%2;
	if(t>=2 && a && c && d) {
		ans += 3;
		a--; c--; d--;
	}
	ans += b + a/2*2 + c/2*2 + d/2*2;
	printf("%lld", ans);
	return 0;
}