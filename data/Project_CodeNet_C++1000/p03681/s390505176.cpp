#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500010
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll fac[MAX]; // n!
ll finv[MAX]; // n!の逆元
ll inv[MAX]; // nの逆元


// n!(fac)とその逆元(finv)を先に計算しておく
void comInit(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	comInit();

	ll N,M;
	cin >> N >> M;

	ans = fac[N] * fac[M] % MOD;
	
	if(abs(N-M) >= 2){
		cout << 0 << endl;
		return 0;
	}

	if(N == M){
		ans = ans * 2 % MOD;
	}
	
	cout << ans << endl;

	return 0;
}
