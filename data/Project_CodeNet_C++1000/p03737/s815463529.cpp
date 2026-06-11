#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    string ans;
    ans += a[0] - 'a' + 'A';
    ans += b[0] - 'a' + 'A';
    ans += c[0] - 'a' + 'A';
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}