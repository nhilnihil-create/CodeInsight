#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;
using namespace __gnu_pbds;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
    return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), s(n + 1, 0);

    REP(i, n) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> t;

    REP(i, n + 1) {
        s[i] -= k * i;
        t.insert(s[i]);
    }

    ll ans = 0;
    REP(i, n + 1) {
        auto itr = t.upper_bound(s[i]);
        t.erase(itr);

        ans += t.size() - t.order_of_key(s[i]);
    }

    cout << ans << endl;

    return 0;
}
