#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
const int N = 1e9;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
typedef long long ll;
int n;
int a[maxn], pre_max[maxn];
std::map<int, int> map;
inline ll get(int v) {
	int & x = map[v];
	auto it = map.upper_bound(v);
	ll ans = 0;
	for(auto i = it;i != map.end();++i) {
		ans += i -> second * ll(i -> first - v);
		x += i -> second;
	}
	map.erase(it, map.end());
	return ans;
}
ll cnt[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		if(a[i] > a[pre_max[i - 1]]) {
			pre_max[i] = i;
		} else {
			pre_max[i] = pre_max[i - 1];
		}
	}
	for(int i = n + 1;i >= 1;) {
		int nxt = pre_max[i - 1];
		for(int j = nxt;j < i;++j) map[a[j]] += 1;
		cnt[i] += get(a[nxt]); i = nxt;
	}
	rep(i, 1, n) {
		cout << cnt[i] << '\n';
	}
}
