
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;

bool know[12][12];


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    LL ans = 1e18;
    rep(x, 1 << n) {
        if (__builtin_popcount(x) < k) continue;
        LL tmp = 0;
        int hi = 0;
        rep(i, n) {
            if (x & (1 << i)) {
                //! building i must be visible
                if (a[i] <= hi) {
                    ++hi;
                    tmp += hi - a[i];
                }
            }
            hi = max(hi, a[i]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
