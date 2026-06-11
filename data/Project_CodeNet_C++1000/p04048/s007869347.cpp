#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;
ll rek(ll a, ll b)
{
    if (a == b)
    {
        return a;
    }
    if (a < b)
    {
        swap(a, b);
    }
    return rek(a - b, b) + b * 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;
    ll ans = n;
    ll a = n - x, b = x;
    while (a && b)
    {
        if (a < b)
        {
            swap(a, b);
        }
        ans += (a / b) * b * 2ll;
        a = a % b;
    }
    ans -= max(a, b);
    cout << ans << endl;
    //cout << rek(n - x, x) + n << "\n";
    return 0;
}