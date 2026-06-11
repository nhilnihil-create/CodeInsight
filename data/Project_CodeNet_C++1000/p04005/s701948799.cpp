#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 1e18;
    if (a % 2 == 0) ans = 0;
    else            ans = min(ans, b * c);

    if (b % 2 == 0) ans = 0;
    else            ans = min(ans, c * a);

    if (c % 2 == 0) ans = 0;
    else            ans = min(ans, a * b);

    cout << ans << endl;
    return 0;
}
