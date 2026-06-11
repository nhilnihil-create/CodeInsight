#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    string s;
    cin >> s;
    int len = s.length();
    int l;
    rep(i, len)
    {
        if (s[i] == 'A')
        {
            l = i;
            break;
        }
    }
    int r;
    for (int i = len - 1; i >= 0; --i)
    {
        if (s[i] == 'Z')
        {
            r = i;
            break;
        }
    }
    cout << r - l + 1 << endl;
}
int main(void)
{
    solve();
}
