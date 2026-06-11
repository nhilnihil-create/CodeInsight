#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200;

int n, p, a[N];
long long d[N][N];

int main() {

	scanf("%d %d", &n, &p);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] %= 2;
	}

	memset(d, 0, sizeof d);

	d[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			d[i + 1][j] += d[i][j];
			d[i + 1][j ^ a[i]] += d[i][j];
		}
	}

	printf("%lld\n", d[n][p]);

	return 0;

}