#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll N;
    cin >> N;

    vector<ll> vec(N);
    for (ll i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    ll add      = 0;
    ll ansCount = 0;
    for (ll i = 1; i < N; ++i) {
        ll tmp = vec[i] - vec[i - 1];
        if (add == 0) {
            add = tmp;
        } else if (tmp == 0) {
        } else {
            bool isSignAdd = add > 0;
            bool isSignTmp = tmp >= 0;
            if (isSignAdd != isSignTmp) {
                ansCount++;
                add = 0;
            }
        }
    }
    ansCount++;
    cout << ansCount << endl;
    return 0;
}