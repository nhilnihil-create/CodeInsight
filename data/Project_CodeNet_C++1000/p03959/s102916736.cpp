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
    ll n;
    cin >> n;
    vl t(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ret = 1;
    if (n == 1) {
        if (t[0] != a[0])
            cout << 0 << "\n";
        else
            cout << 1 << "\n";
        return 0;
    }
    if ((a[0] > a[1] && t[0] != a[0]) || (t[n - 1] > t[n - 2] && t[n - 1] != a[n - 1])) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (t[i] > t[i - 1]) {
            if (t[i] > a[i]) {
                cout << 0 << "\n";
                return 0;
            }
            continue;
        }
        if (a[i] > a[i + 1]) {
            if (t[i] < a[i]) {
                cout << 0 << "\n";
                return 0;
            }
            continue;
        }
        ret = (ret * min(t[i], a[i])) % MOD;
    }
    cout << ret << "\n";
    return 0;
}