#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MOD = 1e9 + 7;
const int MAX_N = 3e5 + 10;


int Inv[MAX_N];
ll mypow(ll a, ll b) {
	ll res = 1, p = a;
	while(b) {
		if(b%2) res = res * p % MOD;
		p = p * p % MOD;
		b >>= 1;
	}
	return res;
}

int H, W, A, B;
int main() {
	cin >> H >> W >> A >> B;
	for(int i=1; i<MAX_N; i++) Inv[i] = mypow(i, MOD-2);
	ll ans = 1;
	ll nowl = 1, nowr = 1;
	for(int i=1; i<=W-1; i++) {
		ans = ans * (H-1+i) % MOD;
		ans = ans * Inv[i] % MOD;
		nowr = nowr * (A-1+i) % MOD;
		nowr = nowr * Inv[i] % MOD;
	}
	ll minus = nowl * nowr % MOD;
	for(int k=1; k<B; k++) {
		nowl = nowl * (H-A-1+k) % MOD;
		nowl = nowl * Inv[k] % MOD;
		nowr = nowr * Inv[(A-1)+(W-1-(k-1))] % MOD;
		nowr = nowr * (W-1-(k-1)) % MOD;
		minus += nowl * nowr % MOD;
		minus %= MOD;
	}
	ans -= minus;
	ans += MOD;
	ans %= MOD;
	printf("%lld\n", ans);
	return 0;
}
