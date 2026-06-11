#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
const double PI = acos(-1);
using namespace std;
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
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    vector<int> sa(n + 1), ta(m + 1);
    rep(i, n) sa[i + 1] = sa[i] + (s[i] == 'A');
    rep(i, m) ta[i + 1] = ta[i] + (t[i] == 'A');
    int q;
    cin >> q;
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--;
        l2--;
        int A = (sa[r1] - sa[l1]) - (ta[r2] - ta[l2]);
        int B =
            ((r1 - l1) - (sa[r1] - sa[l1])) - ((r2 - l2) - (ta[r2] - ta[l2]));
        cout << ((A + 2 * B) % 3 == 0 && (2 * A + B) % 3 == 0 ? "YES" : "NO")
             << endl;
    }
}
