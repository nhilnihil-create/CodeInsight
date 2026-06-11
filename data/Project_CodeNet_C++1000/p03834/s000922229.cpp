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
    rep(i, s.size()) if (s[i] == ',') s[i] = ' ';
    cout << s << endl;
}

int main()
{
    solve();
    return 0;
}