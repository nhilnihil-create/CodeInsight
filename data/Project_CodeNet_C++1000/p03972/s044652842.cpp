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
    ll w, h;
    cin >> w >> h;
    vl p(w);
    for (int i = 0; i < w; ++i) {
        cin >> p[i];
    }
    vl q(h);
    for (int i = 0; i < h; ++i) {
        cin >> q[i];
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    ll ret = 0;
    for (int i = 0; i < w; ++i) {
        ret += p[i];
    }
    for (int i = 0; i < h; ++i) {
        ret += q[i];
    }
    for (int i = 0; i < w; ++i) {
        ret += p[i] * ll(q.end() - upper_bound(q.begin(), q.end(), p[i]));
    }
    for (int i = 0; i < h; ++i) {
        ret += q[i] * ll(p.end() - lower_bound(p.begin(), p.end(), q[i]));
    }
    cout << ret << "\n";
    return 0;
}