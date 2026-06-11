#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
struct RangeSum{
    vector<T> cs;
    RangeSum(const vector<T>& v){
        cs.resize(v.size());
        REP(i, v.size()){
            cs.at(i) = v.at(i);
            if(i > 0){
                cs.at(i) += cs.at(i - 1);
            }
        }
    }
    T query(ll l, ll r){
        if(l >= r || cs.size() == 0){ return 0; }
        r = min((ll)cs.size(), r);
        T ret = cs.at(r - 1);
        if(l > 0){
            ret -= cs.at(l - 1);
        }
        return ret;
    }
};


int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), a2(n);
    REP(i, n){
        cin >> a.at(i);
        a2.at(i) = max(0LL, a.at(i));
    }

    RangeSum<ll> rs1(a), rs2(a2);

    ll ans = numeric_limits<ll>::min();
    REP(i, n - k + 1){
        ll tmp = rs2.query(0, i) + rs2.query(i + k, n);
        ans = max(ans, tmp);
        ans = max(ans, tmp + rs1.query(i, i + k));
    }
    cout << ans << endl;
    return 0;
}
