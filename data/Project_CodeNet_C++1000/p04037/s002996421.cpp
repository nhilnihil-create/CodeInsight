#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 100005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

int n, a[MAXN];

inline bool cmp(int x, int y) {
	return x > y;
}

void init() {
	read(n);
	for (int i=1;i<=n;++i) {
		read(a[i]);
	}
	sort(a+1, a+n+1, cmp);
}

void solve() {
	int t = 0;
	while (a[t] >= t) ++t;
	--t;
	if (!((a[t] - t) & 1)) {
		int i = 0;
		while (a[t+i] >= t) ++i;
		if (i & 1) {
			puts("Second");
			return;
		}
	}
	puts("First");
}

int main() {
	init();
	solve();
	return 0;
}
