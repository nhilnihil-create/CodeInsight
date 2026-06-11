#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    string o, e;
    cin >> o >> e;
    string ans = "";
    rep(i, o.length())
    {
        ans += o[i];
        if (i < e.length())
            ans += e[i];
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}
