#include <bits/stdc++.h>
using namespace std;

long long K;
int n;
long long a[55];

int main() {
	scanf("%lld", &K);
	n = 50;
	for (int i = 1; i <= n; ++i) a[i] = n - 1;
	for (int i = 1; i <= n; ++i) a[i] += K / n;

	K %= n;
	for (int i = 1; i <= n; ++i) {
		if (K == 0) break;
		a[i] += n;
		for (int j = 1; j <= n; ++j) if (j != i) a[j]--;
		--K;
	}

	printf("%d\n", n);
	for (int i = 1; i <= n; ++i) printf("%lld ", a[i]); printf("\n");
}