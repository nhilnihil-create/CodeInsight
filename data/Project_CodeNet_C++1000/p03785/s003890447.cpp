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
    ll N, C, K;
    cin >> N >> C >> K;

    vector<ll> T(N);
    rep(i, N) cin >> T[i];

    sort(ALL(T));

    vector<ll> lims(N);
    rep(i, N) { lims[i] = T[i] + K; }

    // repv(lims) cout << *it << " ";
    // cout << endl;

    ll idx = 0, ans = 0;
    for (ll i = 0; i < N;) {
        ans++;
        idx = i;
        while (i < N && lims[i] <= lims[idx] + K && i - idx < C) {
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}