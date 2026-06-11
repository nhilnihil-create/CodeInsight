#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
	int x = 0, fh = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') fh = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * fh;
}
const int N = 1010;
int a, b, c, d, ans, i, v[N];
int main() {
	a = read(); b = read(); c = read(); d = read();
	for (i = a + 1; i <= b; i++) v[i] = 1;
	for (i = c + 1; i <= d; i++) if (v[i]) ans++;
	cout << ans << '\n';
	return 0;
}