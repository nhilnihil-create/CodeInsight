 //
#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define f first
#define s second
#define what_is(x) cerr << #x << " is " << x << endl;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

ll powMod(ll n, ll p, ll mod) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= n) %= mod;
		(n *= n) %= mod;
		p >>= 1;
	}
	return res;
}
ll invMod(ll n, ll mod) {
	return powMod(n, mod - 2, mod);
}

const signed FACT_MAX_N = 2000006;
signed fact[FACT_MAX_N];
signed factInv[FACT_MAX_N];
struct INIT_FACT {
	INIT_FACT() {
		fact[0] = 1;
		for (int i = 1; i < FACT_MAX_N; ++i) fact[i] = (long long)i * fact[i - 1] % MOD;
		factInv[FACT_MAX_N - 1] = powMod(fact[FACT_MAX_N - 1], MOD - 2, MOD);
		for (int i = FACT_MAX_N - 2; i >= 0; --i) factInv[i] = (long long)(i + 1) * factInv[i + 1] % MOD;
	}
} init_fact;

/* n,r<=10^6, query O(1)*/
ll Permutation(int n, int r) {
	if (r == 0) return 1;
	if (n < r) return 0;
	return (long long)fact[n] * factInv[n - r] % MOD;
}
ll Combination(int n, int r) {
	if (r == 0) return 1;
	if (n < r) return 0;
	return (long long)fact[n] * factInv[n - r] % MOD * factInv[r] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h, w;
    cin >> h >> w;
    int a, b;
    cin >> a >> b;
    ll tot = Combination(h+w-2, h-1);
    ll sub = 0;
    for(int i=0; i<b; i++)
    {
        sub = (sub + ((Combination(i+h-a-1, i)* Combination(a+w-i-2, a-1)) % MOD)) % MOD;
    }
    cout << (tot + MOD - sub) % MOD;
    return 0;
}
