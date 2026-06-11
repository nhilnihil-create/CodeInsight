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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[7];
    rep(i, 7) cin >> a[i];
    int ans = a[1] + (a[0] / 2 + a[3] / 2 + a[4] / 2) * 2;
    if (a[0] > 0 && a[3] > 0 && a[4] > 0)
    {
        a[0]--, a[3]--, a[4]--;
        int tmp = a[1] + 3 + (a[0] / 2 + a[3] / 2 + a[4] / 2) * 2;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}