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

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<int64_t> b(n + 1), c(n + 1);
    irep(i, n)
    {
        if (i == 0) {
            b[i] = c[i] = 0;
        } else {
            b[i] = b[i - 1] + a[i - 1];
            c[i] = c[i - 1] + max(a[i - 1], 0);
        }
    }

    int64_t result = 0;
    irep(i, n - k)
    {
        int64_t score = max(b[i + k] - b[i], 0L) + c[i] + (c[n] - c[i + k]);
        result = max(result, score);
    }
    cout << result << endl;
    return 0;
}