#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int gcd(int a, int b) {
	return (b) ? (gcd(b, a % b)) : a;
}

int n;
int a[N];

boolean solve() {
	int c[2] = {0, 0};
	boolean aflag = false;
	for (int i = 1; i <= n; i++) {
		c[a[i] & 1]++;
		if (a[i] == 1) {
			aflag = true;
		}
	}
	if (aflag) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum ^= (a[i] - 1) & 1;
		}
		return sum;
	}
	if ((!(c[0] & 1)) && c[1] >= 2) {
		return false;
	} else if ((c[0] & 1) && c[1] >= 1) {
		return true;
	}
	int x = 1, g = 0;
	while (!(a[x] & 1))
		x++;
	--a[x];
	for (int i = 1; i <= n; i++)
		g = gcd(a[i], g);
	for (int i = 1; i <= n; i++)
		a[i] /= g;
	return !solve();
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	boolean ans = solve();
	puts((ans) ? ("First") : ("Second"));
	return 0;
}
