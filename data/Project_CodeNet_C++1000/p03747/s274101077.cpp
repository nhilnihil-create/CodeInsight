#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 5e5 + 9;

int n, L, T, w[N], x[N], t;

int main () {
	scanf("%d%d%d", &n, &L, &T);
	for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &w[i]);
	for (int i = 0, j; i < n; ++i) {
		if (w[i] == 1) {
			j = x[i] + T;
			t = (j / L + t) % n;
			j %= L;
		} else {
			j = x[i] - T;
			if (j < 0) t = ((j + 1) / L - 1 + t) % n;
			j %= L;
			if (j < 0) j += L;
		}
		x[i] = j;
	}
	sort(x, x + n);
	if (t < 0) t += n;
	for (int i = 0; i < n; ++i) {
		printf("%d\n", x[(i + t) % n]);
	}
	return 0;
}