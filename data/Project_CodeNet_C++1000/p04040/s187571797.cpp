#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll modPow(const ll a, const ll n, const ll p)
{
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    ll num = modPow(a, n / 2, p);
    return (num * num) % p;
}

int main()
{
    ll H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<ll> modFact(H + W + 1);
    vector<ll> modFactInv(H + W + 1);

    // フェルマーの小定理を用いて、(x!)の逆元を求める
    modFact[0] = 1;
    modFactInv[0] = modPow(modFact[0], MOD - 2, MOD);
    for (ll i = 1; i <= H + W; ++i)
    {
        modFact[i] = (modFact[i - 1] * i) % MOD;
        modFactInv[i] = modPow(modFact[i], MOD - 2, MOD);
    }

    ll ans = 0;
    for (ll i = B; i <= W - 1; ++i)
    {
        ll first, second;
        first = (((modFact[i + H - A - 1] * modFactInv[H - A - 1]) % MOD) * modFactInv[i]) % MOD;
        second = (((modFact[W - i + A - 2] * modFactInv[A - 1]) % MOD) * modFactInv[W - 1 - i]) % MOD;
        ans += (first * second) % MOD;
        ans = ans % MOD;
    }

    cout << ans << endl;
}
