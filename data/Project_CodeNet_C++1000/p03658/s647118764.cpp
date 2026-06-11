#include <algorithm>
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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> sums;

    // rep(i, N) {
    //     reps(j, i + 1, N) {
    //         reps(k, j + 1, N) { sums.push_back(a[i] + a[j] + a[k]); }
    //     }
    // }

    sort(a.begin(), a.end(), greater<int>());
    // sums.erase(unique(a.begin(), a.end()), a.end());

    ll ans = 0;
    rep(i, K) ans += a[i];

    cout << ans << endl;
    // repv(sums) { cout << *it << " "; }
    // cout << sums[2] << endl;

    return 0;
}