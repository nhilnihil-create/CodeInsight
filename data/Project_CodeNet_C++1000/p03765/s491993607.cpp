#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
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

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

ll N, M, K, Q, W, H, L, R, C;
string S, T;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> S >> T >> q;
    vector<int> a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    }
    int s = (int)S.size();
    int t = (int)T.size();
    vector<ll> sa(s + 1), sb(s + 1);
    vector<ll> ta(t + 1), tb(t + 1);

    for (int i = 0; i < s; i++) {
        if (S[i] == 'A') {
            sa[i + 1] = 1;
        } else {
            sb[i + 1] = 1;
        }
    }
    for (int i = 0; i < t; i++) {
        if (T[i] == 'A') {
            ta[i + 1] = 1;
        } else {
            tb[i + 1] = 1;
        }
    }
    for (int i = 0; i < s; i++) {
        sa[i + 1] += sa[i];
        sb[i + 1] += sb[i];
    }
    for (int i = 0; i < t; i++) {
        ta[i + 1] += ta[i];
        tb[i + 1] += tb[i];
    }

    vector<bool> ans(q);
    for (int i = 0; i < q; i++) {
        ll snum = (sa[b[i]] - sa[a[i] - 1]) + (sb[b[i]] - sb[a[i] - 1]) * 2;
        ll tnum = (ta[d[i]] - ta[c[i] - 1]) + (tb[d[i]] - tb[c[i] - 1]) * 2;
        //cout << snum << " " << tnum << endl;
        if (snum % 3 == tnum % 3) {
            ans[i] = true;
        } else {
            ans[i] = false;
        }
    }
    for (int i = 0; i < q; i++) {
        if (ans[i]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
