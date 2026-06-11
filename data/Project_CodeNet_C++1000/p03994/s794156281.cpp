#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;
    string s;
    ll K;
    cin >> s >> K;

    vector<ll> dist;
    rep(i, SZ(s)) {
        if (s[i] == 'a') {
            dist.pb(0);
        } else {
            dist.pb(26 - (s[i] - 'a'));
        }
    }

    // repv(dist) { cout << *it << " "; }
    // cout << endl;

    rep(i, SZ(s)) {
        if (dist[i] <= K) {
            s[i] = 'a';
            K -= dist[i];
            dist[i] = 0;
        }
        // cout << s << ", K: " << K << endl;
    }

    K = K % 26;
    s[SZ(s) - 1] += K;

    cout << s << endl;

    return 0;
}