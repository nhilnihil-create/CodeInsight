//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define f first
#define s second
#define eb emplace_back
#define sz(s) ((int) s.size ())
#define all(s) (s.begin (), s.end ())

using namespace std;

typedef long long ll;

const int N = (int) 1e6 + 5;
const int mod = (int) 1e9 + 7;

int n, dp[N];
ll s;

inline void solve () {
        scanf ("%d", &n);
        dp[0] = 1; dp[1] = n; s = n + 1;
        for (int i = 2; i <= n; i++) {
                dp[i] = ((n - 1) * 1LL * (n - 1) + s - dp[i - 2] + n - i + 1) % mod;
                s += dp[i];
        }
        printf ("%d\n", dp[n]);
}

int tests = 1;

int main () {
//        freopen (".in", "r", stdin);
//        freopen (".out", "w", stdout);
//        scanf ("%d", &tests);
        while (tests--) {
                solve ();
        }
        return 0;
}
