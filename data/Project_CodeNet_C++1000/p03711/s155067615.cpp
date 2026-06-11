#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int x, y;
    cin >> x >> y;
    int gidx = 0, gidy = 0;
    if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
        gidx = 1;
    if (x == 4 || x == 6 || x == 9 || x == 11)
        gidx = 2;
    if (x == 2)
        gidx = 3;
    if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
        gidy = 1;
    if (y == 4 || y == 6 || y == 9 || y == 11)
        gidy = 2;
    if (y == 2)
        gidy = 3;
    if (gidx == gidy)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}