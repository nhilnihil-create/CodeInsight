#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    int n;
    cin >> n;
    vl x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    ll l, q;
    cin >> l >> q;
    vl a(q), b(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vvl dbl(n, vl(20, n - 1));
    int nxt = 0;
    for (int i = 0; i < n; ++i) {
        while (x[nxt] - x[i] <= l && nxt < n) {
            nxt++;
        }
        nxt--;
        dbl[i][0] = nxt;
    }
    for (int i = 1; i <= 17; ++i) {
        for (int j = 0; j < n; ++j) {
            dbl[j][i] = dbl[dbl[j][i - 1]][i - 1];
        }
    }
    auto check = [&](int mid, int i) {
        int l = min(a[i], b[i]);
        int r = max(a[i], b[i]);
        for (int j = 17; j >= 0; --j) {
            if (mid & 1 << j)
                l = dbl[l][j];
        }
        return r <= l;
    };
    for (int i = 0; i < q; ++i) {
        int ok = n;
        int ng = 0;
        while (ng + 1 != ok) {
            int mid = (ok + ng) / 2;
            if (check(mid, i))
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << "\n";
    }
    return 0;
}