#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int n, a[N], g[N];
int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}
bool ok() {
	long long sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	if (n == 1 && a[1] == 1) return 0;
	if (n == 1) return 1;
	if (!(n & 1)) return sum & 1;
	if ((n & 1) && !(sum & 1)) return 1;
	
	for (int j = 0; ; j ^= 1) {
		g[n] = a[n];
		long long S = a[n] - 1; int G;
		for (int i = n - 1; i; i--) g[i] = gcd(g[i + 1], a[i]), S += a[i];
		bool flag = 0;
		if (a[1] > 1 && (1 & (S / (G = gcd(g[2], a[1] - 1))))) flag = 1, a[1]--;
		else 
			for (int i = 2, f = a[1]; i <= n; f = gcd(f, a[i]), i++)
				if (a[i] > 1) {
					int now = gcd(f, a[i] - 1);
					if (i < n) now = gcd(now, g[i + 1]);
					if (1 & (S / (G = now))) {
						flag = 1;
						a[i]--;
						break;
					}
				}
				else break;
		if (!flag) return j;
		for (int i = 1; i <= n; i++) a[i] /= G;
	}
}
 main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	puts(ok() ? "First" : "Second");
	return 0;
}