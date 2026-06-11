#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


void Main()
{
    ll n;
    cin >> n;

    vector<ll> primeCnt(n+1);
    for (ll i = 2; i <= n; i++) {
        auto primes = prime_factorize(i);
        rep(j, primes.size()) {
            ll v = primes[j].first;
            primeCnt[v] += primes[j].second;
        }
    }
    
    ll MOD = 1000000007;
    ll res = 1;
    rep(i, primeCnt.size()) {
        res = (res * (1 + primeCnt[i])) % MOD;
    }
    put(res);
}
signed main(){ Main();return 0;}