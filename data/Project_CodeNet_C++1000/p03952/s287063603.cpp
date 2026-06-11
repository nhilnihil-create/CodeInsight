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
    if (x == 1 || x == 2 * n - 1)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    vector<int> ans(2 * n - 1);
    for (int i = 0; n + i - 1 < 2 * n - 1; i += 2)
    {
        ans[n + i - 1] = (x + i - 1) % (2 * n - 1) + 1;
    }
    for (int i = 0; n - i - 1 >= 0; i += 2)
    {
        ans[n - i - 1] = (x - i - 1 + 2 * n - 1) % (2 * n - 1) + 1;
    }
    for (int i = 0; n + i < 2 * n - 1; i += 2)
    {
        ans[n + i] = (x - 1 - i - 1 + 2 * n - 1) % (2 * n - 1) + 1;
    }
    for (int i = 0; n - i >= 0; i += 2)
    {
        ans[n - i] = (x - 1 + i - 1 + 2 * n - 1) % (2 * n - 1) + 1;
    }

    rep(i, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}