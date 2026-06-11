#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1<<20, mod = 1e9 + 7;
int fact[maxn], inv[maxn];
void calc() {
	for(int i = 0; i < maxn; i++) {
		if(i < 2) fact[i] = inv[i] = 1;
		else fact[i] = i, inv[i] = mod - (mod/i)*1ll*inv[mod%i]%mod;
	}
	for(int i = 1; i < maxn; i++) fact[i] = fact[i]*1ll*fact[i-1]%mod;
	for(int i = 1; i < maxn; i++) inv[i] = inv[i]*1ll*inv[i-1]%mod;
}
int nck(int n, int k) {
	if(k > n || n < 0 || k < 0) return 0;
	int t = fact[n]*1ll*inv[k]%mod;
	return t*1ll*inv[n-k]%mod;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	calc();
	int n, m, a, b;
	cin >> n >> m >> b >> a;
	int ans = nck(n+m-2, n-1);
	for(int i = 0; i < a; i++) {
		ans = (ans + mod - nck(n-b-1+i, i)*1ll*nck(m-i-1+b-1, b-1)%mod)%mod;
	}
	cout << ans;
}
