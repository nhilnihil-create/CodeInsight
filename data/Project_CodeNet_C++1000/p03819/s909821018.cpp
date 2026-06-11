#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 300300;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, m;
int tag[maxn];
inline void add(int a,int b) {
	const int N = std::max(a, b) + 1;
	++ tag[1], --tag[std::abs(b - a) + 1];
	for(int i = std::abs(b - a) + 1;i < N;) {
		const int A = a / i, B = b / i;
		int nxt = std::min<int>(i <= a ? a / A + 1 : N, i <= b ? b / B + 1 : N);
		if(A != B) ++ tag[i], -- tag[nxt];
		i = nxt;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) {
		int l, r;
		l = m, r = m;
		cin >> l >> r;
		add(l - 1, r);
	}
	rep(i, 1, m) {
		cout << (tag[i] += tag[i - 1]) << '\n';
	}
	std::cerr << double(clock()) / CLOCKS_PER_SEC << '\n';
}
