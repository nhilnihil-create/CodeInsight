#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    if (s == t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}