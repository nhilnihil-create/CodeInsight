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
    int64_t ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;

    int64_t result = ao + ai / 2 * 2 + aj / 2 * 2 + al / 2 * 2;
    if (ai > 0 && aj > 0 && al > 0) {
        int64_t tmp = ao + 3 + (ai - 1) / 2 * 2 + (aj - 1) / 2 * 2 + (al - 1) / 2 * 2;
        result = max(result, tmp);
    }

    cout << result << endl;
    return 0;
}