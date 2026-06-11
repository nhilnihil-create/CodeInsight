#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1000200;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n;
int f[maxn];
int suf[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n, f[n] = n, f[n - 1] = (ll) n * n % mod;
	suf[n] = n, suf[n - 1] = (f[n] + f[n - 1]) % mod;
	for(int i = n - 2;i >= 1;--i) {
		f[i] = (f[i + 1] + (ll) (n - 1) * (n - 1) + suf[i + 3] + i + 1) % mod;
		suf[i] = (suf[i + 1] + f[i]) % mod;
	}
	cout << f[1] << '\n';
}
