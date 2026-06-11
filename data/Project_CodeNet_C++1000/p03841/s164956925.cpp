#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
#define N 250005

using namespace std;
typedef pair<int,int> Pair;

inline int input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

int n, num[N];
int x[N];

Pair a[N];

void Exit() { puts("No"); exit(0); }

int main() {
	n = input();
	for (int i = 1; i <= n; ++i) {
		x[i] = input();
		a[i].fi = x[i], a[i].se = i;
	}

	sort(a + 1, a + n + 1);

	int pos = 1, cnt;
	for (int i = 1; i <= n; ++i) {
		cnt = 0;
		if (num[a[i].fi]) Exit();
		num[a[i].fi] = a[i].se;
		if (a[i].se == 1) continue;
		while (pos <= a[i].fi) {
			if (!num[pos]) {
				num[pos] = a[i].se, ++cnt;
				if (cnt == a[i].se - 1) break;
			}
			++pos;
		}

		if (cnt < a[i].se - 1) Exit();
	}

	pos = n * n;
	for (int i = n; i; --i) {
		cnt = 0;
		if (a[i].se == n) continue;
		while (pos >= a[i].fi) {
			if (!num[pos]) {
				num[pos] = a[i].se, ++cnt;
				if (cnt == n - a[i].se) break;
			}
			--pos;
		}

		if (cnt < n - a[i].se) Exit();
	}

	puts("Yes");
	for (int i = 1; i < n * n; ++i)
		printf("%d ", num[i]);
	printf("%d\n", num[n * n]);
	return 0;
}
