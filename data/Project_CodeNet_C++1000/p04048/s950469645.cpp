#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll dfs(ll x, ll y)
{
    if (x % y == 0)
    {
        return (2 * x) - y;
    }
    else
    {
        return (x / y) * y * 2 + dfs(y, x % y);
    }
}
int main()
{
    IOS;
    ll n, x;
    cin >> n >> x;
    ll ans = n;
    n -= x;
    ans += dfs(max(n, x), min(n, x));
    cout << ans << endl;
    return 0;
}
