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

    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    int ans = 0;
    rep(i, n) if ((k | a[i]) == k) ans += b[i];
    for (int bit = 31; bit >= 0; bit--)
    {
        if (!(k & (1 << bit)))
            continue;
        int sum = 0, num = k - (1 << bit);
        for (int i = bit - 1; i >= 0; i--)
            num |= (1 << i);
        rep(i, n) if ((num | a[i]) == num) sum += b[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}