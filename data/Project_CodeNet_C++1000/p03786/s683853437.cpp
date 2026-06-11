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

    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    sort(ALL(A));
    // repv(A) cout << *it << " ";
    // cout << endl;

    vector<ll> sum(N, 0);
    sum[0] = A[0];
    reps(i, 1, N) { sum[i] = sum[i - 1] + A[i]; }
    // repv(sum) cout << *it << " ";
    // cout << endl;

    ll ans = 1;
    repr(i, N - 2) {
        // cout << sum[i] * 2 << ", " << A[i + 1] << endl;
        if (sum[i] * 2 >= A[i + 1]) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}