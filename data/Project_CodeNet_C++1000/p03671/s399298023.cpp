#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << min({a + b, a + c, b + c}) << endl;
}

int main()
{
    solve();
    return 0;
}