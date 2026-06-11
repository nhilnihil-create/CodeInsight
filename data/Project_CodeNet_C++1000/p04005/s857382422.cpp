#pragma GCC optimize("trapv")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 + 100, INF = 1e9 * 1e9 + 10, MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char grid[502][502], ansBl[502][502], ansR[502][502];
bool usd[502];

signed main()
{
    fastInp;

    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = INF;

    if (a % 2 == 0 || c % 2 == 0 || b % 2 == 0) {
        cout << "0";
        return 0;
    }

    ll m = a / 2;
    ans = min(ans, b * c);
    ans = min(ans, c * a);
    ans = min(ans, b * a);

    cout << ans;
    return 0;
}