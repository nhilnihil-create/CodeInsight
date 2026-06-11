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
    vl a(n);
    map<int, vi> idxl, idxr;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i != n - 1)
            idxl[a[i]].push_back(i);
        if (i != 0)
            idxr[a[i]].push_back(i);
    }
    ll mid = 0;
    ll ret = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i])
            mid++;
        ll diff = a[i] - a[i - 1];
        if (diff < 0)
            diff += m;
        ret += min(a[i], diff);
    }
    ll temp = ret;
    for (int i = 2; i <= m; ++i) {
        temp -= mid;
        if (idxl.count(i - 1) != 0) {
            mid += idxl[i - 1].size();
        }
        if (idxr.count(i - 1) != 0) {
            for (auto &p : idxr[i - 1]) {
                mid--;
                temp++;
                ll diff = a[p] - a[p - 1];
                if (diff < 0)
                    diff += m;
                temp += diff - 1;
            }
        }
        chmin(ret, temp);
    }
    cout << ret << "\n";
    return 0;
}