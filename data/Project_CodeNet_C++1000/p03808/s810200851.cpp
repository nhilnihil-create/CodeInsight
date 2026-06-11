#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

typedef long long ll;

ll v1;
int n = 0;
int A[maxn], B[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	v1 = A[1];
	B[1] = A[1] - A[n];
	for (int i = 2; i <= n; i++) B[i] = A[i] - A[i-1];
	int mx = 0, ok = 1;
	for (int i = 1; i <= n; i++) mx = max(mx, B[i]);
	for (int i = 1; i <= n; i++) {
		if ((B[i] - mx) % n != 0) {
			ok = 0;
		}
	}
	if (!ok) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = (mx - B[i]) / n;
		int cost = (n + 2 - i);
		if (cost > n) cost -= n;
		v1 -= 1LL * cnt * cost;
	}
	if (v1 < 0) puts("NO");
	else {
		ll t = 1LL * n * (n+1) / 2;
		if (v1 % t == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}