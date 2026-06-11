#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 3000010;
int n, m, a, b, ans;
int fac[N], ifac[N];

inline int add(const int &x, const int &y) {
	return x + y < mod ? x + y : x + y - mod;
}
inline int sub(const int &x, const int &y) {
	return x - y < 0 ? x - y + mod : x - y;
}
inline int mul(const int &x, const int &y) { return (int)((ll)x * y % mod); }
inline int get(int x, int y) {
	return mul(fac[x + y - 2], mul(ifac[x - 1], ifac[y - 1]));
}
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for(int i = 2; i <= n + m; i++) fac[i] = mul(fac[i - 1], i);
	for(int i = 2; i <= n + m; i++)
		ifac[i] = mul(mod - mod / i, ifac[mod % i]);
	for(int i = 2; i <= n + m; i++) ifac[i] = mul(ifac[i - 1], ifac[i]);
	ans = get(n, m);
	for(int i = 1, ss; i <= b; i++) {
		ss = mul(get(n - a, i), get(a, m - i + 1));
		ans = sub(ans, ss);
	}
	printf("%d\n", ans);
	return 0;
}