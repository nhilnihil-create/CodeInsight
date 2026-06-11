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
int a[maxn], b[maxn], n;
bool chk(int x) {
	rep(i, 1, n + n - 1) b[i] = a[i] >= x;
	rep(i, 0, n - 2) {
		if(b[n - i] == b[n - i - 1]) return b[n - i];
		if(b[n + i] == b[n + i + 1]) return b[n + i];
	}
	return b[n] ^ (n & 1) ^ 1;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n + n - 1) cin >> a[i];
	int l = 1, r = n + n;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		if(chk(mid)) l = mid;
		else r = mid;
	}
	cout << l << '\n';
}
