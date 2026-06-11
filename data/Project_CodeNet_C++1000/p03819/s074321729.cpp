#include <cstdio>
#include <vector>
using namespace std;

#define iter(i, n) for (int i = 1; i <= n; ++i)
#define NR 201000

int t[NR], n, m, ans[NR];
vector<int> fac[NR], s[NR];

void inc(int x) { for (++x; x; x -= x & -x) ++t[x]; }
int sum(int x) { int s = 0; for (++x; x <= n + 10; x += x & -x) s += t[x]; return s; }

int main() {
	scanf("%d%d", &m, &n);
	iter(i, m) {
		int l, r;
		scanf("%d%d", &l, &r);
		s[r + 1].push_back(l - 1);
		//if (0<=l-1&&r+1<=9) printf("[%d %d]\n", l-1, r+1);
	}
	iter(i, 2 * n) for (int j = i; j <= 2 * n; j += i) fac[j].push_back(i);
	iter(i, 2 * n) {
		for (int l : s[i]) inc(l);
		for (int d : fac[i]) {
			ans[d] -= sum(i - d);
			//if (d == n - 1) printf("[%d %d %d]\n", i-d, i, sum(i-d));
		}
	}
	iter(i, n) printf("%d\n", ans[i] + m);
	return 0;
}
