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
    int n, m;
    cin >> n >> m;
    vi x(n);
    map<int, multiset<int>> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        cnt[x[i] % m].insert(x[i]);
    }
    ll ret       = 0;
    auto pairing = [&](int nmin, int &nmax, multiset<int> &mset) {
        auto it = mset.begin();
        while (nmax > nmin && next(it) != mset.end()) {
            if (*it == *next(it)) {
                ret++;
                nmax -= 2;
                it = next(it, 2);
            } else {
                ++it;
            }
        }
    };
    int mmax = m / 2;
    if (m % 2 == 1)
        mmax++;
    for (int i = 1; i < mmax; ++i) {
        int ni  = cnt[i].size();
        int nj  = cnt[m - i].size();
        auto it = cnt[m - i].begin();
        if (ni > nj)
            pairing(nj, ni, cnt[i]);
        else if (ni < nj)
            pairing(ni, nj, cnt[m - i]);
        ret += min(ni, nj);
    }
    ret += cnt[0].size() / 2;
    if (m % 2 == 0) {
        ret += cnt[m / 2].size() / 2;
    }
    cout << ret << "\n";
    return 0;
}