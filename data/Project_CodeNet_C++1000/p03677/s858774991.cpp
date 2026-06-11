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
int n, m;
int a[maxn];
ll tag[maxn], s;
inline void add(int l,int r,int v) { tag[l] += v, tag[r + 1] -= v; }
inline void add(int l,int r) {
	if(r < l) r += m;
	s += r - l, ++ l;
	add(l + 1, r, 1);
	add(r + 1, r + 1, l - r);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
	}
	rep(i, 2, n) {
		add(a[i - 1], a[i]);
	}
	rep(i, 1, m + m) {
		tag[i] += tag[i - 1];
	}
	rep(i, 1, m + m) {
		tag[i] += tag[i - 1];
	}
	ll ans = 1e18;
	rep(i, 1, m) {
		ans = std::min(ans, s - tag[i] - tag[i + m]);
	}
	cout << ans << '\n';
}
