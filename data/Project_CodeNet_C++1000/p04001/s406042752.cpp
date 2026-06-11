#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

ll ans;
int n;
string s;

void dfs(int i, string t)
{
    if (i == n)
    {
        if (t.back() != '+')
            return;
        // cout << t << endl;
        ll tmp = 0;
        rep(j, t.size())
        {
            if (t[j] == '+')
            {
                ans += tmp;
                tmp = 0;
            }
            else
            {
                tmp *= 10;
                tmp += t[j] - '0';
            }
        }
        return;
    }
    dfs(i + 1, t + s[i]);
    dfs(i + 1, t + s[i] + "+");
}

void solve()
{
    cin >> s;
    n = s.size();
    dfs(0, "");
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}