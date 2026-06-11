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
int a[maxn];
int n, k;
ll ans;
inline void solve(int l,int r) {
	if(l == r) return void(ans += a[l] >= 0);
	std::vector<ll> v0, v1;
	int mid = l + r >> 1; ll s = 0;
	for(int i = mid;i >= l;--i) v0.push_back(s += a[i]);
	std::sort(v0.begin(), v0.end()), s = 0;
	for(int i = mid + 1;i <= r;++i) {
		s += a[i], ans += v0.end() - std::lower_bound(v0.begin(), v0.end(), - s);
	}
	solve(l, mid), solve(mid + 1, r);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], a[i] -= k;
	solve(1, n);
	cout << ans << '\n';
}
