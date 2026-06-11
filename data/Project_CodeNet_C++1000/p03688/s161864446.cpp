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
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    int lb = 0, ub = n;
    rep(i, n)
    {
        ub = min(ub, a[i] + 1);
        lb = max(lb, a[i]);
    }
    //cout << "lb, ub= " << lb << " " << ub << endl;

    for (int i = lb; i <= ub; i++)
    {
        int x = 0, y = 0;
        rep(j, n)
        {
            if (a[j] == i - 1)
            {
                x++;
            }
            if (a[j] == i)
            {
                y++;
            }
        }
        if (x + y != n)
        {
            continue;
        }

        int w = i - x;
        int z = (n - x) / 2;

        //cout << "i=" << i << " x=" << x << " y=" << y << " z=" << z << endl;
        if (w >= 0)
        {
            if (y == 0 || (i - x >= 1 && i - x <= z))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}