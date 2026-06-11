#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    ll x;
    cin >> x;

    // 最小回数にするためには、最初が5 -> 6 -> 5 -> 6と続く
    ll ans;
    if (x <= 6)
    {
        ans = 1;
    }
    else if (x > 6 && x <= 11)
    {
        ans = 2;
    }
    else
    {
        ans += x / 11;
        x %= 11;
        if (x == 0)
        {
            ans *= 2;
        }
        else if (x != 0 && x <= 6)
        {
            ans = ans * 2 + 1;
        }
        else
        {
            ans = ans * 2 + 2;
        }

        // if (x % 11 == 0)
        // {
        //     ans = x / 11 * 2;
        // }
        // else
        // {
        //     ans = x / 11 * 2 + 1;
        // }
    }
    cout << ans << endl;
    return (0);
}