#include <cstdio>
#include <algorithm>
using namespace std;
 
#define iter(i, n) for (int i = 1; i <= n; ++i)
 
#define NR 101000

typedef long long i64;

int n, L, T, x[NR], w[NR], ans[NR];

typedef pair<int, int> pii;

pii y[NR];

#define fi first
#define se second

int N(i64 i) { return (i - 1) % n + 1; }


int main() {
	//freopen("13C.in", "r", stdin);
	//freopen("13C.out", "w", stdout);
	scanf("%d%d%d", &n, &L, &T);
	int pos = -1, index;
	iter(i, n) {
		scanf("%d%d", &x[i], &w[i]);
		if (w[i] == 1 && pos == -1) {
			pos = x[i];
			index = i;
		}
		y[i] = pii((0ll + x[i] + (w[i] == 1 ? +T : -T) % L + L) % L, w[i]);
	}
	if (pos == -1) {
		iter(i, n) printf("%d\n", y[i].fi);
		return 0;
	}

	i64 d = 0;
	iter(i, n) {
		if (w[i] == 2) {
			d += 2 * (T / L);
			int _T = T % L;

			if (x[i] < pos) {
				if (x[i] + L - 2 * _T < pos) ++d;
				if (x[i] + L - 2 * _T < pos - L) ++d;
			}
			if (x[i] > pos) {
				if (x[i] - 2 * _T < pos) ++d;
				if (x[i] - 2 * _T < pos - L) ++d;
			}
		}
	}

	pii tmp = y[index];
	//fprintf(stderr, "!%d %d %lld %d\n", tmp.fi, index, d, T / L);
	sort(y + 1, y + n + 1);
	iter(i, n) {
		if (y[i] == tmp) {
			iter(j, n) {
				ans[N((j-1) + index + d)] = y[N(i)].fi;
				++i;
			}
			iter(j, n) printf("%d\n", ans[j]);
			break;
		}
	}
	return 0;
}
