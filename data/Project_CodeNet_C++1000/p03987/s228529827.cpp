#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<int, int>> P(n);

    rep(i, n) {
        int x;
        cin >> x;
        P[i] = {x, i + 1};
    }
    sort(ALL(P));
    set<int> st;
    st.insert(0);
    st.insert(n + 1);

    ll ret = 0;
    for(auto p : P) {
        int id = p.second;
        auto i = st.lower_bound(id);
        int r = *i--;
        int l = *i;
        ret += 1LL * p.first * (r - id) * (id - l);
        st.insert(p.second);
    }
    cout << ret << endl;

    return 0;
}