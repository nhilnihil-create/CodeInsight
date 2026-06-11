#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

long long n, k, mx, a[N], s[N], l[N], r[N];
int main() {
	int i;
	scanf("%d%d", &n, &k);
	for(i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		s[i] = s[i-1] + a[i];
		l[i] = l[i-1] + max(0LL, a[i]);
	}
	for(i=n; i>=k; i--) {
		r[i] = r[i+1] + max(0LL, a[i]);
		mx = max(mx, l[i-k] + r[i+1] + max(0LL, s[i] - s[i-k]));
	}
	printf("%lld", mx);
	return 0;
}