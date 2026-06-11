// guruguru
// * frank_c1
// * 2017 / 11/ 07

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = (int)(1e5) + 5;
LL D[maxn], U[maxn];
int a[maxn];

int main() {
	int n, m, dt = 0; LL ret = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); --a[i];
		if (i > 1) {
			int u = a[i - 1], v = a[i]; 
			if (u > v) ret += v + 1, dt++; else ret += (v + m - u) % m;
			D[(u + 1) % m]++; D[(v + 1) % m]--; U[(v + 1) % m] += (v + m - u) % m;
		}
	} LL mi = ret; 
	for (int i = 1; i < m; ++i) {
		ret += U[i]; ret -= dt; dt += D[i]; mi = min(mi, ret); 
	}
	return printf("%lld\n", mi), 0;
}