// Ants on a Circle
// * frank_c1
// * 2017 / 11 / 17

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = (int)(1e5) + 5;
int a[maxn], w[maxn];
pii b[maxn];

int main() {
	int n, L, T;
	scanf("%d%d%d", &n, &L, &T);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &w[i]);
		b[i] = make_pair((int)((a[i] + (w[i] == 1 ? 1LL : L - 1LL) * T) % L), w[i]);
	} pii now = b[0]; 
	sort(b, b + n); T = T * 2 - 1; LL cnt = 0, s = w[0] == 1 ? 1LL : n - 1LL;
	for (int i = 1; i < n; ++i) if (w[0] != w[i]) {
		int dt = w[i] == 2 ? (a[i] + L - a[0]) % L : (a[0] + L - a[i]) % L;
		if (dt <= T) (cnt += s * (1 + (T - dt) / L)) %= n;
	}
	int p = 0; while (now != b[p]) ++p; (p += n - cnt) %= n;
	for (int i = 0; i < n; ++i) printf("%d\n", b[p].first), (p += 1) %= n;
	return 0;
}