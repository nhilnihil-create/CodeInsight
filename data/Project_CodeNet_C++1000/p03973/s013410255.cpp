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

    int d = 1;
    int64_t result = 0;
    rep(i, n)
    {
        if (i == 0) {
            result += a[i] - 1;
            d = 2;
        } else {
            int q = a[i] / d, r = a[i] % d;
            if (r == 0) {
                result += q - 1;
                if (q == 1) {
                    d++;
                }
            } else {
                result += q;
            }
        }
    }
    cout << result << endl;

    return 0;
}