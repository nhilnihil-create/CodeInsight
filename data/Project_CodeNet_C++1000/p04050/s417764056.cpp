#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }

    if (m == 1)
    {
        if (n == 1)
        {
            cout << 1 << endl
                 << 1 << endl
                 << 1 << endl;
        }
        else
        {
            cout << a[0] << endl
                 << 2 << endl
                 << a[0] - 1 << " " << 1 << endl;
        }
    }
    else
    {
        sort(a.begin(), a.end(), [&](int u, int v) {
            return (u & 1) < (v & 1);
        });

        if (m >= 3 && (a[m - 3] & 1))
        {
            cout << "Impossible" << endl;
        }
        else
        {
            swap(a[0], a[m - 2]);

            for (auto x : a)
                cout << x << " ";
            cout << endl;

            cout << a.size() - (a[0] == 1) << endl;

            if (a[0] > 1)
                cout << a[0] - 1 << " ";
            for (int i = 1; i + 1 < m; ++i)
            {
                cout << a[i] << " ";
            }

            cout << a[m - 1] + 1 << endl;
        }
    }

    return 0;
}