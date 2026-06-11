#include <bits/stdc++.h>


using namespace std;

const int N = 100100;

int x[N];
int dx[N];
int p[N];


int ans[N], tmp[N];

int main() {
	int n, m;
	long long k;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n-1; ++i) {
		dx[i] = x[i+1] - x[i];
	}
	scanf("%d%lld", &m, &k);

	for (int i = 0; i < n-1; ++i) {
		p[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		int y;
		scanf("%d", &y);
		y--;
		swap(p[y-1], p[y]);
	}

	for (int i = 0; i < n-1; ++i) {
		ans[i] = i;
	}
	// tem outro jeito que achar o ciclo explicitamente, mas esse mais facil codar...
	for (;k; k >>= 1) {
		if (k & 1) {
			for (int i = 0; i < n-1; ++i) {
				tmp[i] = ans[p[i]];
			}
			for (int i = 0; i < n-1; ++i) {
				ans[i] = tmp[i];
			}
		}

		for (int i = 0; i < n-1; ++i) {
			tmp[i] = p[p[i]];
		}
		for (int i = 0; i < n-1; ++i) {
			p[i] = tmp[i];
		}
	}
	long long val = x[0];
	printf("%lld\n", val);
	for (int i = 0; i < n-1; ++i) {
		val += dx[ans[i]];
		printf("%lld\n", val);
	}
}