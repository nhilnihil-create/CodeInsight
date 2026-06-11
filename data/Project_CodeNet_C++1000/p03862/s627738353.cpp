#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    ll res = 0;
    rep(i, n)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            if (a[i] > x)
            {
                res += a[i] - x;
                a[i] = x;
            }
        }
        else
        {
            if (a[i] + a[i - 1] > x)
            {
                int rm = a[i] + a[i - 1] - x;
                res += rm;
                rm -= a[i];
                a[i] = abs(rm);
                if (rm > 0)
                {
                    rm -= a[i - 1];
                    a[i - 1] = abs(rm);
                }
            }
        }
    }
    cout << res << endl;
}
