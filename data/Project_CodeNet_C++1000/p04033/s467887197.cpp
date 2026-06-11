#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    ll a, b;
    cin >> a >> b;
    string ans;
    if (a > 0)
    {
        ans = "Positive";
    }
    else if (a < 0 && b > 0)
        ans = "Zero";
    else
    {
        if (b > 0)
        {
            if (abs(a) % 2 == 1)
                ans = "Positive";
            else
                ans = "Negative";
        }
        else
        {
            if (abs(a - b) % 2 == 1)
                ans = "Positive";
            else
                ans = "Negative";
        }
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}