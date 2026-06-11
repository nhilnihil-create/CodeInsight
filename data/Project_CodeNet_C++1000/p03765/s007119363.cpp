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
    string s, t;
    cin >> s >> t;
    int q;
    cin >> q;
    vi a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vi ssum(s.size(), 0), tsum(t.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A')
            ssum[i] = 1;
        else
            ssum[i] = 2;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == 'A')
            tsum[i] = 1;
        else
            tsum[i] = 2;
    }
    for (int i = 1; i < s.size(); ++i) {
        ssum[i] += ssum[i - 1];
    }
    for (int i = 1; i < t.size(); ++i) {
        tsum[i] += tsum[i - 1];
    }
    ssum.insert(ssum.begin(), 0);
    tsum.insert(tsum.begin(), 0);
    for (int i = 0; i < q; ++i) {
        int snum = ssum[b[i]] - ssum[a[i] - 1];
        int tnum = tsum[d[i]] - tsum[c[i] - 1];
        if (snum % 3 == tnum % 3)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}