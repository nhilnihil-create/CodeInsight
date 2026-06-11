#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read() {
	LL x = 0, fh = 1;
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
int n, i;
LL ans, x;
LL gcd(LL a, LL b) { return (b == 0 ? a : gcd(b, a % b)); }
LL lcm(LL a, LL b) { return max(a, b) / gcd(a, b) * min(a, b); }
int main() {
	n = read(); ans = read();
	for (i = 2; i <= n; i++) ans = lcm(ans, read());
	cout << ans << '\n';
	return 0;
}