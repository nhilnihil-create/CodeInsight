#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    rep(i, n - m + 1)
    {
        rep(j, n - m + 1)
        {
            int cta = 0;
            rep(k, m)
            {

                string tmp = a[k + i].substr(j, m);
                if (tmp == b[k])
                    cta++;
            }
            if (cta == m)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}
int main(void)
{
    solve();
}
