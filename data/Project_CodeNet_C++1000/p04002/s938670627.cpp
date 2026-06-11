#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int maxd = 10;

int n, cnt;
int a[maxn], b[maxn];
long long h, w;
long long ans[maxd];
map < int, map < int, bool > > point;

signed main () {
	scanf("%lld %lld %d", &h, &w, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &a[i], &b[i]);
		point[a[i]][b[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int dx = -2; dx <= 0; ++dx) {
			for (int dy = -2; dy <= 0; ++dy) {
				if (a[i] + dx < 1 || b[i] + dy < 1 || a[i] + dx + 2 > h || b[i] + dy + 2 > w)
					continue;
				else {
					cnt = 0;
					for (int x = a[i] + dx; x <= a[i] + dx + 2; ++x) {
						for (int y = b[i] + dy; y <= b[i] + dy + 2; ++y) 
							cnt += point[x][y];
					}
					++ans[cnt];
				}
			}
		}
	}
	ans[0] = (h - 2) * (w - 2);
	for (long long i = 1; i < maxd; ++i) {
		ans[i] /= i;
		ans[0] -= ans[i];
	}
	for (int i = 0; i < maxd; ++i)
		printf("%lld\n", ans[i]);
}
