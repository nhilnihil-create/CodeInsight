#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    int n;
    cin >> n;
    long long ct, ca;
    ct = 1;
    ca = 1;
    REP(i, n)
    {
        long long t, a;
        cin >> t >> a;
        long long x = (ct + t - 1) / t;
        long long y = (ca + a - 1) / a;
        long long maxv = max(x, y);
        ct = maxv * t;
        ca = maxv * a;
    }
    cout << ct + ca << endl;
}