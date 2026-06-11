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
    string ans = "";
    deque<char> q;
    rep(i, s.size())
    {
        if (s[i] == 'B' && q.size() > 0)
            q.pop_back();
        if (s[i] == 'B')
            continue;
        else
            q.emplace_back(s[i]);
    }
    for (auto i : q)
        cout << i;
    cout << endl;
}
int main(void)
{
    solve();
}
