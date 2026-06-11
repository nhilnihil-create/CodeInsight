#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int N = 205;
int n, m, cnt, a[N], b[N];

bool cmp (int x, int y) {
	bool s1 = x & 1, s2 = y & 1;
	return s1 > s2;
}
int main () {
	cin >> n >> m, cnt = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
		if (a[i] & 1) ++cnt;
	}
	if (m == 1) {
		if (n <= 2) return printf("%d\n%d\n%d\n", a[1], 1, n), 0;
		printf("%d\n", a[1]);
		printf("%d\n", 2);
		if (n & 1) printf("%d %d\n", 1, n - 1);
		else printf("%d %d\n", 2, n - 2);
		return 0;
	}
	if (cnt > 2) return puts("Impossible"), 0;
	sort(a + 1, a + 1 + m, cmp), swap(a[2], a[m]);
	b[1] =  a[1] - 1;
	for (int i = 2; i < m; ++i) b[i] = a[i];
	b[m] = a[m] + 1;
	for (int i = 1; i <= m; ++i) printf("%d%c", a[i], i < m ? ' ' : '\n');
	cout << (b[1] ? m : m - 1) << endl;
	for (int i = b[1] ? 1 : 2; i <= m; ++i) printf("%d%c", b[i], i < m ? ' ' : '\n');
	return 0;
}