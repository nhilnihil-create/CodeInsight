#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
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
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }
    vvl dbl(n, vl(20));
    for (int i = 0; i < n; ++i) {
        dbl[i][0] = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin() - 1;
    }
    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i < n; ++i) {
            dbl[i][j] = dbl[dbl[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < q; ++i) {
        auto check = [&](ll mid) {
            int s = a[i];
            int k = 0;
            while (mid) {
                if (mid & 1)
                    s = dbl[s][k];
                k++;
                mid >>= 1;
            }
            return b[i] <= s;
        };
        ll ok = n;
        ll ng = 0;
        while (abs(ok - ng) != 1) {
            ll mid = (ng + ok) / 2;
            if (check(mid))
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << "\n";
    }
    return 0;
}