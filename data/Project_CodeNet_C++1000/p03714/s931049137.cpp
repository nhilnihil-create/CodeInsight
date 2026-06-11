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
    priority_queue<ll, vl, greater<ll>> l, r;
    vector<ll> a(3 * n);
    ll lsum = 0, rsum = 0;
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }
    vector<ll> ls(n + 1), rs(n + 1);
    for (int i = 0; i < n; ++i) {
        l.push(a[i]);
        lsum += a[i];
    }
    ls[0] = lsum;
    for (int i = n; i < 2 * n; ++i) {
        lsum += a[i];
        l.push(a[i]);
        lsum -= l.top();
        l.pop();
        ls[i - n + 1] = lsum;
    }
    for (int i = 2 * n; i < 3 * n; ++i) {
        r.push(-a[i]);
        rsum -= a[i];
    }
    rs[n] = rsum;
    for (int i = 2 * n - 1; i >= n; --i) {
        rsum -= a[i];
        r.push(-a[i]);
        rsum -= r.top();
        r.pop();
        rs[i - n] = rsum;
    }
    ll ret = -INF;
    for (int i = 0; i <= n; ++i) {
        chmax(ret, ls[i] + rs[i]);
    }
    cout << ret << "\n";
    return 0;
}