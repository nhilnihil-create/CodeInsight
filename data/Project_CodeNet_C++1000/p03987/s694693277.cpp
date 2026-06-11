#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a.at(i);
    }

    vector<int> pla(n);
    for (int i=0; i<n; ++i) {
        pla.at(a.at(i)-1) = i;
    }

    set<int> st;
    ll res = 0;
    for (int i=0; i<n; ++i) {
        st.insert(pla.at(i));
        auto iter = st.find(pla.at(i));
        ll l, r;
        if (iter == st.begin()) {
            l = -1;
        } else {
            --iter;
            l = *iter;
            ++iter;
        }
        ++iter;
        if (iter == st.end()) r = n;
        else r = *iter;

        res += (ll)(i+1) * (r-pla.at(i)) * (pla.at(i)-l);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
