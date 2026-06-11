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
typedef long long ll;

int main(void)
{
    ll x;
    cin >> x;
    ll tmp = x / 11;
    ll ans = tmp * 2;
    ll amari = x % 11;
    if (amari > 0)
    {
        if (amari <= 6)
        {
            ans += 1;
        }
        else
        {
            ans += 2;
        }
    }
    cout << ans << endl;
}