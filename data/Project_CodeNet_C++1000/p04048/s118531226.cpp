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

int64_t f(int64_t x, int64_t y)
{
    if (x == 0) {
        return -y;
    }
    return y / x * 2 * x + f(y % x, x);
}

int main()
{
    int64_t n, x;
    cin >> n >> x;

    cout << n + f(min(x, n - x), max(x, n - x)) << endl;

    return 0;
}