#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    sort(all(s));
    int ans = 0;
    rep(i, n) ans += s[i];
    if (ans % 10 == 0)
    {
        rep(i, n)
        {
            if (s[i] % 10 != 0)
            {
                ans -= s[i];
                cout << ans << endl;
                return;
            }
        }
        cout << 0 << endl;
    }
    else
        cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}