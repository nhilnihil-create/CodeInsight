#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long INFLL = 1LL << 60;
const long long MOD = 1e9 + 7;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> wa(0), su(0);
    rep(i, 1, 31) rep(j, 31) if(A * i * 100 + B * j * 100 <= F)
        wa.push_back(A * i + B * j);
    rep(i, F) rep(j, F) if(C * i + D * j <= F) su.push_back(C * i + D * j);
    double cma = -1;
    int wma = 0, sma = 0;
    for(auto w : wa) {
        for(auto s : su) {
            if(w * 100 + s > F) continue;
            if(w * E < s) continue;
            if(chmax(cma, 100.0 * s / double(w * 100 + s))) {
                wma = w;
                sma = s;
            }
        }
    }
    cout << wma * 100 + sma << " " << sma << endl;
}