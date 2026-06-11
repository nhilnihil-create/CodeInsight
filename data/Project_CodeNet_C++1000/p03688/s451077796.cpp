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
    vi a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    if (cnt.size() == 1) {
        int colors = a[0];
        if ((1 <= colors && colors <= n / 2) || colors == n - 1)
            cout << "Yes"
                 << "\n";
        else
            cout << "No"
                 << "\n";
        return 0;
    }
    if (cnt.size() > 2) {
        cout << "No"
             << "\n";
        return 0;
    }
    int a1, a2;
    a1 = cnt.begin()->first;
    a2 = cnt.rbegin()->first;
    if (a1 + 1 != a2) {
        cout << "No"
             << "\n";
        return 0;
    }
    int b1, b2;
    b1            = cnt.begin()->second;
    b2            = cnt.rbegin()->second;
    int colorsmin = b1 + 1;
    int colorsmax = b1 + b2 / 2;
    if (colorsmin <= a2 && a2 <= colorsmax) {
        cout << "Yes"
             << "\n";
    } else {
        cout << "No"
             << "\n";
    }
    return 0;
}