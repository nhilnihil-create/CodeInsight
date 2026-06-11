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
    map<char, int> mp;
    rep(i, s.length())
    {
        mp[s[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second % 2 == 1)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}
int main(void)
{
    solve();
}
