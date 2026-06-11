#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
int n, q[300], l = 150, r = 149;

void Dfs (ll x) {
	if (x == 1) return ;
	if (x & 1) {
		Dfs(x - 1);
		q[--l] = ++n;
	} else {
		Dfs(x >> 1);
		q[++r] = ++n;
	}
}

int main () {
	scanf("%lld", &N);
	Dfs(N + 1);
	printf("%d\n", n << 1);
	for (int i = l; i <= r; ++i) printf("%d ", q[i]);
	for (int i = 1; i <= n; ++i) printf("%d ", i);
	return 0;
}