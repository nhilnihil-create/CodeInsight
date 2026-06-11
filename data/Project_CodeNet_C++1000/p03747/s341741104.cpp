#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
int N; ll L, T;
ll A[MAXN];
int c;

int main() {
	register int i;
	scanf("%d%lld%lld", &N, &L, &T);
	for(i = 1; i <= N; ++i) {
		ll x, w;
		scanf("%lld%lld", &x, &w); w = w == 2 ? -1 : w;
		x = x + w * T;
		if(x > 0) c += x / L, c %= N;
		if(x < 0) c += (x + 1) / L - 1, c %= N;
		A[i] = (x % L + L) % L;
	}
	c = (c + N) % N;
	sort(A + 1, A + N + 1);
	for(i = c + 1; i <= N; ++i) printf("%d\n", A[i]);
	for(i = 1; i <= c; ++i) printf("%d\n", A[i]);
	return 0;
}