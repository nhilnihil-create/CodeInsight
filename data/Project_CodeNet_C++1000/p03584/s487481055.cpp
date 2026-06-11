#include <algorithm>
#include <bitset>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }

    int64_t result = 0;
    rep(i, n)
    {
        if ((~k & a[i]) == 0) {
            result += b[i];
        }
    }
    rep(i, 30)
    {
        if (((k >> i) & 1) == 1) {
            int mask = ((~(k >> (i + 1)) << 1) + 1) << i;

            int64_t score = 0;
            rep(i, n)
            {
                if ((a[i] & mask) == 0) {
                    score += b[i];
                }
            }
            result = max(result, score);
            //cout << i << " " << bitset<30>(mask) << endl;
        }
    }
    cout << result << endl;

    return 0;
}