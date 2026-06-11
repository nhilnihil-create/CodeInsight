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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    rep(i, n)
    {
        cin >> a[i];
    }

    int64_t result = numeric_limits<int64_t>::max();
    vector<int> minCost(n);
    copy(a.begin(), a.end(), minCost.begin());
    rep(i, n)
    {
        rep(j, n)
        {
            minCost[j] = min(minCost[j], a[(j - i + n) % n]);
        }

        int64_t total = i * x;
        rep(j, n)
        {
            total += minCost[j];
        }
        result = min(result, total);
    }
    cout << result << endl;

    return 0;
}