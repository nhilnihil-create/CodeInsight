#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

const int64_t MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    vector<int> t(n), a(n);
    rep(i, n)
    {
        cin >> t[i];
    }
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<int> ub(n), lb(n);
    fill(ub.begin(), ub.end(), numeric_limits<int>::max());
    fill(lb.begin(), lb.end(), 1);

    rep(i, n)
    {
        if (i == 0) {
            ub[i] = lb[i] = t[i];
        } else {
            ub[i] = min(ub[i], t[i]);
            if (t[i] > t[i - 1]) {
                lb[i] = max(lb[i], t[i]);
            }
        }
    }
    rrep(i, n)
    {
        if (i == n - 1) {
            ub[i] = min(ub[i], a[i]);
            lb[i] = max(lb[i], a[i]);
        } else {
            ub[i] = min(ub[i], a[i]);
            if (a[i] > a[i + 1]) {
                lb[i] = max(lb[i], a[i]);
            }
        }
    }

    int64_t result = 1;
    rep(i, n)
    {
        int64_t x = max(0, ub[i] - lb[i] + 1);
        x %= MOD;
        result *= x;
        result %= MOD;
    }
    cout << result << endl;

    return 0;
}