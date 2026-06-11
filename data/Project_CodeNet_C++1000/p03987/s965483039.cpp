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
    vector<pll> a;
    for (int i = 0; i < n; ++i) {
        ll aa;
        cin >> aa;
        a.emplace_back(aa, i);
    }
    sort(a.begin(), a.end());
    set<int> idx;
    idx.insert(-1);
    idx.insert(n);
    ll ret = 0;
    for (auto &p : a) {
        ll r   = *idx.upper_bound(p.second);
        ll l   = *prev(idx.upper_bound(p.second));
        ll cnt = (r - p.second-1) * (p.second - l-1) + (r - l - 1);
        ret += p.first * cnt;
        idx.insert(p.second);
    }
    cout << ret << "\n";
    return 0;
}