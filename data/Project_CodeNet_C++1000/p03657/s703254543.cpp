#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b;
    cin >> a >> b;
    bool ok = false;
    if (a % 3 == 0)
        ok = true;
    if (b % 3 == 0)
        ok = true;
    if ((a + b) % 3 == 0)
        ok = true;
    if (ok)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}

int main()
{
    solve();
    return 0;
}