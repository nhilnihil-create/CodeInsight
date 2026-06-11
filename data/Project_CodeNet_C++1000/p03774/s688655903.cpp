#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
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
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 100000;
ll const MOD = 1000000007;
ll const MAX_V = 10000;
ll const MAX_E = 10000;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N), b(N), c(M), d(M);

    rep(i, N) cin >> a[i] >> b[i];
    rep(i, M) cin >> c[i] >> d[i];

    rep(i, N) {
        ll dist_min = INF;
        ll idx = -1;
        rep(j, M) {
            ll dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (dist < dist_min) {
                dist_min = dist;
                idx = j + 1;
            }
        }
        cout << idx << endl;
    }

    return 0;
}
