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
    vector<int> p(n);
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
    }

    vector<int> a(n), b(n);
    rep(i, n)
    {
        a[i] = i * n + 1;
        b[i] = n * n - i * n + 1;
    }

    rep(i, n)
    {
        a[p[i]] += i;
    }

    rep(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    rep(i, n)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}