#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n){ cin >> a.at(i); }

    vector<ll> cs(n, 0), cs2(n, 0);
    REP(i, n){
        cs.at(i) = a.at(i);
        cs2.at(i) = max(a.at(i), 0LL);
        if(i > 0){
            cs.at(i) += cs.at(i - 1);
            cs2.at(i) += cs2.at(i - 1);
        }
    }
    const auto rngsum = [](const vector<ll>& cs, ll l, ll r) -> ll {
        if(l >= r || cs.size() == 0){ return 0; }
        r = min((ll)cs.size(), r);
        ll ret = cs.at(r - 1);
        if(l > 0){
            ret -= cs.at(l - 1);
        }
        return ret;
    };

    ll ans = numeric_limits<ll>::min();
    REP(i, n - k + 1){
        ll tmp = rngsum(cs2, 0, i) + rngsum(cs2, i + k, n);
        ans = max(ans, tmp);
        ans = max(ans, tmp + rngsum(cs, i, i + k));
    }
    cout << ans << endl;
    return 0;
}
