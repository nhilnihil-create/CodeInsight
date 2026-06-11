#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 250005;
struct Data { int x, p; } dat[MAXN];
int arr[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		dat[i] = Data { x, i };
	}
	sort(dat + 1, dat + 1 + n, [&](const Data &a, const Data &b) { return a.x < b.x; });
	for (int i = 1; i <= n; i++) {
		int x = dat[i].x, c = dat[i].p - 1;
		for (int j = 1; c && j < x; j++) if (!arr[j])
			arr[j] = dat[i].p, --c;
		if (c > 0) return puts("No"), 0;
		arr[x] = dat[i].p;
	}
	for (int i = n; i > 0; i--) {
		int x = dat[i].x, c = n - dat[i].p;
		for (int j = n * n; c && j > x; j--) if (!arr[j])
			arr[j] = dat[i].p, --c;
		if (c > 0) return puts("No"), 0;
	}
	puts("Yes");
	for (int i = 1; i <= n * n; i++) printf("%d ", arr[i]);
	return 0;
}