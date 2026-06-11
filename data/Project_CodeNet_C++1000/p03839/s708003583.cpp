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
    ll n, k;
    cin >> n >> k;
    vl a(n), b(n);
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = max(0ll, a[i]);
        tot += b[i];
    }
    // if (n == 1) {
    //     cout << max(0LL, a[0]) << "\n";
    //     return 0;
    // }
    vl sum(n, 0), possum(n, 0);
    sum[0]    = a[0];
    possum[0] = b[0];
    for (int i = 1; i < n; ++i) {
        sum[i]    = sum[i - 1] + a[i];
        possum[i] = possum[i - 1] + b[i];
    }
    ll ret = -INF;
    for (int i = 0; i <= n - k; ++i) {
        ll temp = tot;
        temp += sum[i + k - 1];
        temp -= possum[i + k - 1];
        if (i != 0) {
            temp -= sum[i - 1];
            temp += possum[i - 1];
        }
        chmax(ret, temp);

        temp -= sum[i + k - 1];
        if (i != 0) {
            temp += sum[i - 1];
        }
        chmax(ret, temp);
    }
    cout << ret << "\n";
    return 0;
}