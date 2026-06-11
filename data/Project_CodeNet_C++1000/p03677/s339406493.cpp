#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, a[100009], p[200009], v;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { cin >> a[i]; if (i >= 2) { v += (a[i] - a[i - 1] + m) % m; } }
	for (int i = 1; i <= n - 1; i++) {
		if ((a[i + 1] - a[i] + m) % m <= 1) continue;
		int L = a[i] + 2, R = a[i + 1] + 1; if (L > R) R += m;
		p[L]++; p[R] -= (R - L + 1); p[R + 1] += (R - L);
	}
	for (int i = 1; i <= 2 * m; i++) p[i] += p[i - 1];
	for (int i = 1; i <= 2 * m; i++) p[i] += p[i - 1];
	
	long long maxn = 0;
	for (int i = 1; i <= m; i++) maxn = max(maxn, p[i] + p[i + m]);
	cout << v - maxn << endl;
	return 0;
}