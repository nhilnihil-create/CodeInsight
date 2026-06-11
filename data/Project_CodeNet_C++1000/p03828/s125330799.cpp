#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

vector<pair<ll, ll> > prime_factorize(ll n){
    vector<pair<ll, ll> > res;
    for(int i = 2; i * i <= n; i++){
        if(n % i != 0) continue;
        ll ex = 0;
        while(n % i == 0){
            ex++;
            n /= i;
        }
        res.push_back({i, ex});
    }
    if(n != 1) res.push_back({n, 1});
    return res;
}

int main() {
    ll N; cin >> N;

    vector<ll> ex(N + 1, 0);
    for(ll i = 2; i <= N; i++){
        const auto &pf = prime_factorize(i);
        for(auto p : pf) ex[p.first] += p.second;
    }
    ll MOD = 1e9 + 7;
    ll ans = 1;
    for(int i = 2; i <= N; i++){
        ans *= ex[i] + 1;
        ans %= MOD;
    }
    cout << ans << endl;
}
