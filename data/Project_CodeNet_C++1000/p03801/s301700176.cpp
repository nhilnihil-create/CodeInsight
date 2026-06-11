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
    vl a(n);
    map<ll, set<int>> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]].insert(i);
    }
    vl ret(n, 0);
    ll size = cnt.rbegin()->second.size();
    while (true) {
        auto p = cnt.rbegin();
        auto pm = next(p);
        if (pm == cnt.rend())
            break;
        ret[*(p->second.begin())] += (p->first - pm->first) * size;
        size += pm->second.size();
        pm->second.insert(*(p->second.begin()));
        cnt.erase(p->first);
    }
    auto p = cnt.rbegin();
    ret[*(p->second.begin())] += (p->first - 0) * size;

    for (auto &r : ret) {
        cout << r << "\n";
    }
    return 0;
}