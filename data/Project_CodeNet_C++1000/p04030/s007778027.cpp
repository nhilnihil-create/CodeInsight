#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    string ans = "";
    rep(i, s.size())
    {
        if (s[i] == '0')
        {
            ans += "0";
        }
        else if (s[i] == '1')
        {
            ans += "1";
        }
        else
        {
            if (!ans.empty())
            {
                // int b = ans.size() - 1;
                // ans.erase(b);
                ans = ans.substr(0, ans.size() - 1);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}