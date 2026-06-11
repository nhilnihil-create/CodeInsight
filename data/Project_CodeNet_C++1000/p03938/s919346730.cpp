#include <bits/stdc++.h>
using namespace std;

int n, p[20005], a[20005], b[20005];

int main() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &p[i]);
	}
	for ( int i = 1; i <= n; i++ ) {
		a[i] = a[i - 1] + 20000;
	}
	for ( int i = n; i > 0; i-- ) {
		b[i] = b[i + 1] + 20000;
	}
	for ( int i = 1; i <= n; i++ ) {
		a[p[i]] -= (n - i);
	}
	for ( int i = 1; i <= n; i++ ) {
		printf(i == n?"%d\n":"%d ", a[i]);
	}
	for ( int i = 1; i <= n; i++ ) {
		printf(i == n?"%d\n":"%d ", b[i]);
	}
	return 0;
}