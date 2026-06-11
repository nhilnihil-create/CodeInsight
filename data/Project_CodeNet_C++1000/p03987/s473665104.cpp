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

int inva[200'000];

int main()
{
    int n;
    cin >> n;
    rep(i, n)
    {
        int j;
        cin >> j;
        inva[j - 1] = i + 1;
    }

    int64_t result = 0;
    set<int> s;
    s.insert(0);
    s.insert(n + 1);

    rep(i, n)
    {
        auto ub = s.upper_bound(inva[i]);
        int R = *ub;
        ub--;
        int L = *ub;
        result += (int64_t)(i + 1) * (inva[i] - L) * (R - inva[i]);
        s.insert(inva[i]);
    }
    cout << result << endl;

    return 0;
}