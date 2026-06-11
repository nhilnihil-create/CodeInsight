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
    int ans = a + b;
    if (ans >= 24)
        ans -= 24;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}