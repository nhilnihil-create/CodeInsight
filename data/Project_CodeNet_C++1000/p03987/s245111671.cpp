#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    rep(i, n) {
        int p;
        cin >> p;
        v[i] = make_pair(p, i);
    }
    sort(all(v));
    vector<int> p(n);
    rep(i, n) {
        p[i] = v[i].second;
    }
    set<int> st;
    st.insert(-1);
    st.insert(n);

    ll ans = 0;
    rep(i, n) {
        int num = i + 1;
        auto itr = st.lower_bound(p[i]);
        int right = *itr;
        itr--;
        int left = *itr;

        ll now = 1;
        now *= (ll)right - p[i];
        now *= (ll)p[i] - left;
        now *= (ll)num;
        ans += now;
        st.insert(p[i]);
    }
    cout << ans << endl;
}
