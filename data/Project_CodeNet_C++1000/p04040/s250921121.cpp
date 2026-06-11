#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll MOD = 1e9 + 7, SIZ = 1e7;
vector<ll> fact;

ll binpow (ll a, ll n, ll md) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow (a, n-1, md) * a) % md;
	else {
		ll b = binpow (a, n/2, md);
		return (b * b) % md;
	}
}

ll cages(ll n, ll k) {
    return (fact[n] * binpow((fact[k] * fact[n - k]) % MOD, MOD - 2, MOD)) % MOD;
}

int main()
{
    fastInp;

    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    ll cr = max(max(h, w), max(a, b));
    fact.push_back(1);
    for (ll i= 1; i <= SIZ; i++) fact.push_back((fact.back() * i) % MOD);

    ll ans = 0, s = 0;
    for (int i = a; i < h; i++) {
        ll cur = 0;
        cur += (cages(b + i - a - 1, i - a) * cages(h + w - (i - a) - b - 2, w - b - 1)) % MOD;

        ans += cur;
        ans += MOD;
        ans %= MOD;
    }

    cout << ans;
    return 0;    
}