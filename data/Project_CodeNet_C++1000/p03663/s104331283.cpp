#include <algorithm>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif
using namespace std;

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int main()
{
    llong val = 1;
    for (; val <= 1e10; val *= 10)
    {
        cout << "? " << to_string(val) << endl;
        string s;
        cin >> s;
        if (s == "N")
            break;
    }
    if (val == 1e11)
    {
        val = 9;
        for (; val <= 1e10; val = 10 * val + 9)
        {
            cout << "? " << to_string(val) << endl;
            string s;
            cin >> s;
            if (s == "Y")
            {
                val *= 10;
                break;
            }
        }
    }
    llong len = to_string(val).size() - 1;
    llong l = pow(10, len - 1);
    llong r = pow(10, len) - 1;
    while (l < r)
    {
        llong mid = (l + r) / 2;
        cout << "? " << to_string(mid * 10) << endl;
        string s;
        cin >> s;
        if (s == "Y")
            r = mid;
        else
            l = mid + 1;
    }
    cout << "! " << r << endl;
    return 0;
}