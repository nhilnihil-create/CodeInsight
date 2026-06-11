#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 5010;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int f[maxn][maxn];
char s[maxn];
int n, L;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> s, L = strlen(s);
	f[0][0] = 1;
	rep(i, 0, n - 1) {
		rep(j, 0, i) {
			f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j] * 2u) % mod;
			f[i + 1][j ? j - 1 : 0] = (f[i + 1][j ? j - 1 : 0] + f[i][j]) % mod;
		}
	}
	cout << f[n][L] * pow(2, mod - 1 - L) % mod << '\n';
}
