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
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    vector<int> v(100'001);
    vector<int> rem(m);
    vector<int> vrem(m);
    rep(i, n)
    {
        cin >> x[i];
        v[x[i]]++;
        rem[x[i] % m]++;
    }

    irep(i, 100'000)
    {
        vrem[i % m] += v[i] / 2;
    }

    int result = 0;
    rep(i, m)
    {
        if (i != 0) {
            if (i == m - i) {
                int s = rem[i] / 2;
                result += s;
                rem[i] %= 2;

            } else {
                int s = min(rem[i], rem[m - i]);
                result += s;
                rem[i] -= s;
                rem[m - i] -= s;
            }
        }
    }

    rep(i, m)
    {
        if (i != 0) {
            int p = rem[i] / 2;
            result += min(p, vrem[i]);
        }
    }

    result += rem[0] / 2;
    cout << result << endl;

    return 0;
}