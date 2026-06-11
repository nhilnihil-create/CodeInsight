#include <cstdio>
typedef long long ll;
int n, a, b, l, r=1e9, m, ans, h[100005];

bool f(int p) {
	ll i, c=0;
	for(i=0; i<n; i++)
		c += h[i] > (ll)p*b ? (h[i]-p*b+a-1)/a : 0;
	return c<=p;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	a -= b;
	for(int i=0; i<n; i++) scanf("%d", &h[i]);
	while(l<=r) {
		m = (l+r) / 2;
		if(f(m)) r = m-1, ans = m;
		else l = m+1;
	}
	printf("%d", ans);
	return 0;
}
