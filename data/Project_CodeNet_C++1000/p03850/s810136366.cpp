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
int n;
ll f[3];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n; f[1] = f[2] = -1e18;
	rep(i, 1, n) {
		char ch = '+'; int x;
		if(i != 1) cin >> ch;
		cin >> x;
		if(ch == '-') x = -x;
		f[0] += x, f[1] -= x, f[2] += x;
		if(ch == '-') {
			f[2] = std::max(f[1], f[2]);
			f[1] = std::max(f[0], f[1]);
		}
		f[1] = std::max(f[1], f[2]);
		f[0] = std::max(f[0], f[1]);
	}
	cout << f[0] << '\n';
}
