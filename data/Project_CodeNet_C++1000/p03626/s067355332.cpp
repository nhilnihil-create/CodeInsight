#include <algorithm>
#include <complex>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define REP(i, m, n) for (int i = int(m); i < int(n); i++)
#define RREP(i, m, n) for (int i = int(n) - 1; i >= int(m); --i)
#define EACH(i, c) for (auto &(i) : c)
#define all(c) begin(c), end(c)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(begin(c), end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x) cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s)                                                               \
    do {                                                                       \
    } while (0)
#define dump(x)                                                                \
    do {                                                                       \
    } while (0)
#define BR
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int, int>;
using VP = vector<PII>;

// struct edge {int from, to, cost;};

constexpr double EPS = 1e-10;
// constexpr double PI  = acos(-1.0);
// constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;
// inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}

template <class T> inline T sqr(T x) { return x * x; }

void solve() {
    int n;
    cin >> n;
    VS s(2);
    cin >> s[0];
    cin >> s[1];
    VLL dp(n);
    if (n == 1) {
        cout << 3 << endl;
        return;
    }
    if (s[0][0] == s[1][0]) {
        dp[0] = 3;
        if (s[0][1] == s[1][1])
            dp[1] = 6;
    } else
        dp[1] = 6;

    REP(i, 2, n) {
        if (s[0][i] == s[1][i]) {
            if (s[0][i - 1] == s[1][i - 1])
                dp[i] = (dp[i - 1] * 2) % MOD;
            else
                dp[i] = dp[i - 1];
        } else if (s[0][i - 1] == s[0][i]) {
            if (s[0][i - 2] == s[1][i - 2])
                dp[i] = (dp[i - 2] * 2) % MOD;
            else
                dp[i] = (dp[i - 2] * 3) % MOD;
        }
    }
    cout << dp[n - 1] << endl;
}

int main() {
    solve();

    return 0;
}