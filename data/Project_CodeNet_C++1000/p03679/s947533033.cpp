#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    string ans;
    ll x, a, b;
    cin >> x >> a >> b;
    if (b <= a)
    {
        ans = "delicious";
    }
    else if (b - a <= x)
    {
        ans = "safe";
    }
    else
    {
        ans = "dangerous";
    }
    cout << ans << "\n";
    return 0;
}
