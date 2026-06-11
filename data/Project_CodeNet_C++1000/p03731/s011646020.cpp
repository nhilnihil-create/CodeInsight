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

#define REP(i, n) for (long long i = 0; i < (n); ++i)
#define rep(i, a, b) for (long long i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    int n, t;
    cin >> n >> t;
    long long ans = 0;
    int cur = t;
    int a[n];
    REP(i, n)
    {
        cin >> a[i];
    }
    REP(i, n - 1)
    {
        ans += min(a[i + 1] - a[i], t);
    }
    ans += t;
    cout << ans << endl;
}