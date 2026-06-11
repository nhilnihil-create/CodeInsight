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
    string a;
    cin >> a;
    int n = a.size();

    vector<int> dp1(n);
    vector<int> dp2(26, 0);
    rep(i, n)
    {
        int c = a[i] - 'a';
        dp1[i] = i - dp2[c];
        dp2[c]++;
    }

    int64_t result = 1;
    rep(i, n)
    {
        result += dp1[i];
    }
    cout << result << endl;

    return 0;
}