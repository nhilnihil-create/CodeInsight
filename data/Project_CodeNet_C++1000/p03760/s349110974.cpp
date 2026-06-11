#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string o, e;
    cin >> o >> e;
    int n = max(o.size(), e.size());
    rep(i, n)
    {
        if (i < o.size())
            cout << o[i];
        if (i < e.size())
            cout << e[i];
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}