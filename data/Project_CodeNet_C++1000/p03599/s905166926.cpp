#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    // dp[i]:=砂糖水i(g)のとき最大の砂糖の質量
    vector<int> dp(F + 1, -INF);
    dp[0] = 0;
    for(int i = 0; i < F; i++) {
        if(i + 100 * A <= F)
            dp[i + 100 * A] = max(dp[i], dp[i + 100 * A]);
        if(i + 100 * B <= F)
            dp[i + 100 * B] = max(dp[i], dp[i + 100 * B]);
        if(i + C <= F && E * ((i - dp[i]) / 100) >= dp[i] + C) {
            dp[i + C] = max(dp[i] + C, dp[i + C]);
        }
        if(i + D <= F && E * ((i - dp[i]) / 100) >= dp[i] + D) {
            dp[i + D] = max(dp[i] + D, dp[i + D]);
        }
    }
    double conc = -1;
    pair<int, int> res = MP(0, 0);
    for(int i = 1; i < F + 1; i++) {
        if(dp[i] == -INF)
            continue;
        double tmp = (100.0 * dp[i]) / (double)i;
        if(conc < tmp) {
            res = MP(i, dp[i]);
            conc = tmp;
        }
    }
    cout << res.first << " " << res.second << endl;
    return 0;
}