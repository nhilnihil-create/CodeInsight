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


int n, s;
int a[100005];
int dp[100005][18];
int dp2[100005][18];
int m;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> s;
    int l = n;
    for (int i = n; i > 0; --i) {
        while (l > i && a[l] - a[i] > s) --l;
        dp[i][0] = l;
        for (int j = 1; j <= 17; ++j)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
    l = 1;
    for (int i = 1; i <= n; ++i) {
        while (l < i && a[i] - a[l] > s) ++l;
        dp2[i][0] = l;
        for (int j = 1; j <= 17; ++j)
            dp2[i][j] = dp2[dp2[i][j - 1]][j - 1];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << '\n';
            continue;
        }
        if (l < r) {
            int res = 0;
            for (int i = 17; i >= 0; --i)
                if (dp[l][i] && dp[l][i] < r) {
                    res += (1 << i);
                    l = dp[l][i];
                }
            ++res;
            cout << res << '\n';
        } else {
            int res = 0;
            for (int i = 17; i >= 0; --i)
                if (dp2[l][i] && dp2[l][i] > r) {
                    res += (1 << i);
                    l = dp2[l][i];
                }
            ++res;
            cout << res << '\n';
        }
    }
    return 0;
}

