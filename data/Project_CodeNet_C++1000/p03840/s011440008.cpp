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
    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    ll ret = 0;
    ret += 2 * (i / 2);
    ret += o;
    ret += (j / 2) * 2;
    ret += (l / 2) * 2;
    if (j % 2 == 1 && l % 2 == 1 && i % 2 == 1) {
        ret += 3;
    } else if (j % 2 == 1 && l % 2 == 1 && i > 0) {
        ret += 1;
    } else if (j % 2 == 1 && i % 2 == 1 && l > 0) {
        ret += 1;
    } else if (i % 2 == 1 && l % 2 == 1 && j > 0) {
        ret += 1;
    }
    cout << ret << "\n";
    return 0;
}