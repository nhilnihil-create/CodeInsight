#include <cstdio>
long long n, a, c, ans=1, M=1e9+7;
int main() {
	scanf("%lld", &n);
	while(n--) {
		scanf("%lld", &a);
		if(a < 2*c+1) ans = ans * (c+1) % M;
		else c++;
	}
	while(c) ans = ans * c-- % M;
	printf("%lld", ans);
}