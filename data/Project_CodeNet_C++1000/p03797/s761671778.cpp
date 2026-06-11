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
const ll infl = 1LL << 60;

int main(void)
{
    long long a, b;
    cin >> a >> b;

    ll ans = 0;
    if (b < a * 2)
    {
        cout << b / 2 << endl;
        return 0;
    }

    b -= a * 2;
    ans += a;
    ans += b / 4;
    cout << ans << endl;
}