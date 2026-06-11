#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int m = ri();
	int a[n], b[n];
	for (int i = 0; i < n; i++) a[i] = ri(), b[i] = ri();
	int c[m], d[m];
	for (int i = 0; i < m; i++) c[i] = ri(), d[i] = ri();
	
	for (int i = 0; i < n; i++) {
		int min = 1000000000;
		int ind = -1;
		for (int j = 0; j < m; j++) {
			int dist = std::abs(c[j] - a[i]) + std::abs(d[j] - b[i]);
			if (dist < min) min = dist, ind = j;
		}
		printf("%d\n", ind + 1);
	}
	
	return 0;
}
