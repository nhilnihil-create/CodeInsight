#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9 + 7;

#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) begin(a), end(a)

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    ll ans = INF;
    REP(i, 1 << N) {
        vector<bool> b(N);
        ll num = 0;
        REP(j, N) {
            b[j] = (i >> j) & 1;
            if (b[j]) num++;
        }
        if (num < K) continue;
        ll cost = 0;
        ll highest = 0;
        REP(j, N) {
            if (b[j]) {
                if (a[j] <= highest) {
                    cost += highest - a[j] + 1;
                    highest++;
                }
            }
            if (a[j] > highest) highest = a[j];
        }
        ans = min(cost, ans);
    }
    cout << ans << endl;
    return 0;
}