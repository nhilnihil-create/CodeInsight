# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;
const long long md = 1e9 + 7;

int n, m;
string s;
int dp[5005][5005];


inline long long pw(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1ll) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    m = (int)s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i + 1][j + 1] += dp[i][j];
            if (dp[i + 1][j + 1] >= md) dp[i + 1][j + 1] -= md;
            dp[i + 1][j + 1] += dp[i][j];
            if (dp[i + 1][j + 1] >= md) dp[i + 1][j + 1] -= md;
            if (j) {
                dp[i + 1][j - 1] += dp[i][j];
                if (dp[i + 1][j - 1] >= md) dp[i + 1][j - 1] -= md;
            } else {
                dp[i + 1][j] += dp[i][j];
                if (dp[i + 1][j] >= md) dp[i + 1][j] -= md;
            }
        }
    }
    long long ans = dp[n][m];
    long long z = pw(pw(2, m), md - 2);
    ans *= z;
    ans %= md;
    cout << ans << '\n';
    return 0;
}

