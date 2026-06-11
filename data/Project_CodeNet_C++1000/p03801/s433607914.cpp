#include <algorithm>
#include <cmath>
#include <functional>
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
    int n;
    cin >> n;

    vector<int> a(n + 1);
    a[0] = 0;
    rep(i, n)
    {
        cin >> a[i + 1];
    }

    vector<int> b(n + 1);
    b[0] = 0;
    rep(i, n)
    {
        if (a[i + 1] > a[b[i]]) {
            b[i + 1] = i + 1;
        } else {
            b[i + 1] = b[i];
        }
    }

    vector<int> c(a);
    sort(c.begin(), c.end());

    vector<int64_t> d(n + 2);
    rirep(i, n + 1)
    {
        if (i == n + 1) {
            d[i] = 0;
        } else {
            d[i] = d[i + 1] + c[i];
        }
    }

    vector<int64_t> result(n + 1, 0);
    int i = b[n];
    while (i != 0) {
        int oldi = i;
        i = b[oldi - 1];

        int oldj = upper_bound(c.begin(), c.end(), a[oldi]) - c.begin();
        int j = upper_bound(c.begin(), c.end(), a[i]) - c.begin();

        int64_t oldp = d[oldj] - (int64_t)(n + 1 - oldj) * a[oldi];
        int64_t p = d[j] - (int64_t)(n + 1 - j) * a[i];

        result[oldi] = p - oldp;
    }

    rep(i, n)
    {
        cout << result[i + 1] << endl;
    }

    return 0;
}