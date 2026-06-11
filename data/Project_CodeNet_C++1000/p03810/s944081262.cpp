#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int n, a[N], t[2], g, b[N], m, num;
bool o;

void Ext (bool o) { puts(o ? "First" : "Second"); exit(0); }
int gcd (int a, int b) { return b ? gcd(b, a % b) : a; }
bool sum () { bool sum = 0; for (int i = 1; i <= n; ++i) sum ^= (a[i] & 1) ^ 1; return sum; }

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	while (1) {
		t[0] = t[1] = m = g = 0;
		if (n <= 1) Ext(o);
		for (int i = 1; i <= n; ++i) ++t[a[i] & 1];
		if ((t[0] & 1) && t[1])
		Ext(o ^ 1);
		if (!(t[0] & 1) && t[1] > 1)
		Ext(o);
		for (int i = 1; i <= n; ++i) if (a[i] & 1) {
		if (a[i] == 1) 
		Ext(sum() ^ o);
		 --a[i];  break;
		}
		for (int i = 1; i <= n; ++i) if (!g) g = a[i]; else g = gcd(g, a[i]);
		for (int i = 1; i <= n; ++i) {
			a[i] /= g;
			b[++m] = a[i];
		}
		if (m != n) o ^= 1;
		for (int i = n = m; i; --i) a[i] = b[i];
		o ^= 1;
	}
	return 0;
}