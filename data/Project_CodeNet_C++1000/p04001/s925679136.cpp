#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for (int i = 0; i < (1 << (n - 1)); i++)
    {
        ll num = 0;
        for (int j = 0; j < n; j++)
        {
            num = num * 10 + (s[j] - '0');
            if ((i >> j) & 1)
            {
                ans += num;
                num = 0;
            }
        }
        ans += num;
    }
    cout << ans << endl;

    return 0;
}
