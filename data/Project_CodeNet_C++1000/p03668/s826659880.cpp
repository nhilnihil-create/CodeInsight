#include <cstdio>
#include <cstring>

const int N = 1e5 + 100;
const int M = N << 1;
int n, h[N], to[M], nx[M], e;

int grundy(int u, int f = -1) {
	int r = 0;
	for (int i = h[u]; i != -1; i = nx[i]) {
		if (to[i] != f) {
			r ^= 1 + grundy(to[i], u);
		}
	}
	return r;
}

int main() {
	e = 0;
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		to[e] = v, nx[e] = h[u], h[u] = e++;
		to[e] = u, nx[e] = h[v], h[v] = e++;
	}
	int t = grundy(1);
	if (t == 0) {
		puts("Bob");
	} else puts("Alice");
	return 0;
}