#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    int w, a, b;
    cin >> w >> a >> b;
    int ans = max(0, max(b - (a + w), a - (b + w)));
    cout << ans << endl;
}
int main(void)
{
    solve();
}
