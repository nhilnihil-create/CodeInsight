#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool ok = false;
    rep(i, n + 1) rep(j, m + 1)
    {
        if (i * (m - j) + j * (n - i) == k)
            ok = true;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}