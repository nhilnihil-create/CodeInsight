#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 1, cnt = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        int pos = 2 * cnt + 1;
        if (pos <= a)
        {
            cnt++;
            continue;
        }
        (ans *= cnt + 1) %= mod;
    }
    for (int i = 1; i <= cnt; i++)
        (ans *= i) %= mod;
    cout << ans << endl;
}
