#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4000;

int a[2*N + 5], n, x;

int le[2*N + 5], ri[N + 5];

ll s[2*N + 5];

int main() {
	scanf("%d%d", &n, &x);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), a[n + i] = a[i];
	a[0] = a[2*n + 1] = 0;
	for(int i=1;i<=2*n;i++) {
		le[i] = i - 1;
		while( a[le[i]] >= a[i] ) le[i] = le[le[i]];
	}
	for(int i=2*n;i>=1;i--) {
		ri[i] = i + 1;
		while( a[ri[i]] > a[i] ) ri[i] = ri[ri[i]];
	}
	for(int i=1;i<=n;i++) {
		int p = (n + i) - le[n + i], q = ri[i] - i;
		s[0] += a[i], s[min(p, q)] -= a[i];
		s[max(p, q)] -= a[i], s[min(p, q) + max(p, q)] += a[i];
		
	}
	
	for(int i=1;i<=n;i++) s[i] += s[i - 1];
	for(int i=1;i<=n;i++) s[i] += s[i - 1];
	
	ll ans = (1ll << 60);
	for(int i=0;i<=n;i++) ans = min(ans, s[i] + 1ll*i*x);
	printf("%lld\n", ans);
}
