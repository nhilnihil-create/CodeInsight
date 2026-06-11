#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int x = 0, ans = 0;
    rep(i, n)
    {
        if (s[i] == 'I')
            x++;
        else
            x--;
        ans = max(ans, x);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}