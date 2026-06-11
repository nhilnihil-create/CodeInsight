#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    REP(i, n){
        cin >> t.at(i);
    }
    REP(i, n){
        cin >> a.at(i);
    }

    vector<pair<ll, ll>> h(n, make_pair(1, 1000000000));
    ll prev_t = 0;
    REP(i, n){
        if(t.at(i) > prev_t){
            h.at(i).first = max(h.at(i).first, t.at(i));
        }
        h.at(i).second = min(h.at(i).second, t.at(i));
        prev_t = t.at(i);
    }

    ll prev_a = 0;
    for(ll i = n - 1; i >= 0; --i){
        if(a.at(i) > prev_a){
            h.at(i).first = max(h.at(i).first, a.at(i));
        }
        h.at(i).second = min(h.at(i).second, a.at(i));
        prev_a = a.at(i);
    }

    ll ans = 1;
    for(auto p : h){
        ans *= max(0LL, (p.second - p.first + 1));
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}
