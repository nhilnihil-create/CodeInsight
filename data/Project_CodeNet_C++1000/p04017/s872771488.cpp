#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, x, q, a[maxn];
int bz[20][maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cin >> x;
	rep(i, 1, n) {
		bz[0][i] = std::upper_bound(a + 1, a + n + 1, a[i] + x) - a - 1;
	}
	bz[0][n + 1] = n + 1;
	rep(i, 1, 19) rep(j, 1, n + 1)
		bz[i][j] = bz[i - 1][bz[i - 1][j]];
	cin >> q;
	rep(i, 1, q) {
		int l, r, ans = 0;
		cin >> l >> r;
		if(l > r) std::swap(l, r);
		for(int i = 19;i >= 0;--i) if(bz[i][l] < r) {
			ans += 1 << i;
			l = bz[i][l];
		}
		cout << ans + 1 << '\n';
	}
}
