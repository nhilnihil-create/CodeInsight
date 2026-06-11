#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define MOD 1000000007
typedef long long ll;

int main(){

	int n,m;cin >> n >> m;
	ll x = 0,y = 0;
	REP(i,n){
		ll tmp;cin >> tmp;
		x += i * tmp % MOD;x %= MOD;
		x += (n - i - 1) * ((MOD - tmp) % MOD) % MOD;x %= MOD;
	}

	REP(i,m){
		ll tmp;cin >> tmp;
		y += i * tmp % MOD;y %= MOD;
		y += (m - i - 1) * ((MOD - tmp) % MOD) % MOD;y %= MOD;
	}

	cout << x * y % MOD << endl;
	return 0;
}
