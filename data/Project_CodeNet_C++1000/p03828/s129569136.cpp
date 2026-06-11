#include <iostream>

using namespace std;

typedef long long ll;

ll mod = 1000000007;

ll *Prime_Factorization(ll N, ll mod) {
    ll *fac = new ll[N+1];
    for (ll i = 2; i <= N; i++)
        fac[i] = 0;
    ll N_ = N;

    for (ll i = 2; i*i <= N; i++) {
        while (N_ % i == 0) {
            fac[i]++;
            N_ /= i;
        }
    }
    if (N_ > 1)
        fac[N_]++;
    return fac;
}

int main() {
    ll N;  cin >> N;

    ll ans = 1;
    ll *cnt = new ll[N+1];
    for (ll i = 0; i <= N; i++)
        cnt[i] = 0;

    for (ll n = 2; n <= N; n++) {
        ll *fac = Prime_Factorization(n, mod);
        for (ll i = 2; i <= n; i++) {
            cnt[i] += fac[i];
        }
    }

    for (ll i = 2; i <= N; i++) {
        ans *= cnt[i]+1;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}