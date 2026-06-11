#include <cstdio>

#define iter(i, n) for (int i = 1; i <= n; ++i)

const int NR = 1e5 + 100;

int n, a[NR], c[2];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main() {
	//freopen("10D.in", "r", stdin);
	scanf("%d", &n);
	iter(i, n) scanf("%d", &a[i]);

	bool cur = 0;
	while (true) {
		c[0] = c[1] = 0;
		iter(i, n) ++c[a[i] % 2];
		if (c[0] % 2 != 0) { cur ^= 1; break; }
		if (c[1] > 1 || c[0] + c[1] == 1) break;
		bool fail = false;
		iter(i, n) if (a[i] % 2) {
			if (a[i] > 1) --a[i];
			else { fail = true; break; }
		}
		if (fail) break;
		int d = a[1];
		iter(i, n) d = gcd(d, a[i]);
		iter(i, n) a[i] /= d;
		cur ^= 1;
	}

	puts(cur ? "First" : "Second");
	return 0;
}
