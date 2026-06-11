#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

typedef long long ll;

int n, A[maxn], cur, res = 0;

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x%y);
}

int solve() {
	ll sum = 0;
	int v1 = 0, c[2];
	c[0] = c[1] = 0;
	for (int i = 1; i <= n; i++) {
		sum += A[i];
		if (A[i] == 1) v1 = 1;
		c[A[i] & 1] ++;
	}
	if (v1) {
		res = ((sum - n) & 1);
		return 1;
	} else {
		if ((sum - n) & 1) {
			res = 1;
			return 1;
		}
		if (c[1] == 1) {
			for (int i = 1; i <= n; i++) if (A[i] & 1) A[i] --;
			int d = A[1];
			for (int i = 1; i <= n; i++) d = gcd(d, A[i]);
			for (int i = 1; i <= n; i++) A[i] /= d;
			return 0;
		} else {
			res = 0;
			return 1;
		}
	}
}

int main() {
	if (n == 1) {
		if (n & 1) puts("Second");
		else puts("First");
		return 0;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	while (!solve()) cur ^= 1;
	if (res ^ cur) puts("First");
	else puts("Second");
	return 0;
}