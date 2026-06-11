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
    ll n, k;
    cin >> n >> k;
    vl a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j <= 30; ++j) {
            if (!((1LL << j) & k) && ((1LL << j) & a[i])) {
                ok = false;
                break;
            }
        }
        if (ok)
            ret += b[i];
    }
    for (int i = 0; i <= 30; ++i) {
        if (!(1LL << i & k))
            continue;
        ll temp = 0;
        ll tempk = k;
        tempk -= 1LL << i;
        for (int j = 0; j < i; ++j) {
            if (!(tempk & 1LL << j))
                tempk += 1LL << j;
        }
        for (int l = 0; l < n; ++l) {
            bool ok = true;
            for (int j = 0; j <= 30; ++j) {
                if (!((1 << j) & tempk) && ((1 << j) & a[l])) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                temp += b[l];
        }
        chmax(ret, temp);
    }
    cout << ret << "\n";
    return 0;
}