#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    rep(i, n)
    {
        if (i == 0 || i % 2 == 1)
            continue;
        s = s.substr(0, n - i);
        string t = s.substr(0, s.size() / 2);
        string u = s.substr(s.size() / 2);
        if (t == u)
        {
            cout << s.size() << endl;
            return;
        }
    }
}

int main()
{
    solve();
    return 0;
}