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

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    rep(i, M) cin >> a[i] >> b[i];

    vector<ll> cnt(N, 0);

    rep(i, M) {
        cnt[a[i] - 1]++;
        cnt[b[i] - 1]++;
    }

    bool flg = true;
    repv(cnt) {
        if (*it % 2 == 1) {
            flg = false;
            break;
        }
    }

    if (flg)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    // repv(cnt) cout << *it << " ";
    // cout << endl;

    return 0;
}
