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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = 0, num = n * (n + 1) / 2;
    rep(i, n) sum += a[i];
    if (sum % num != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    sum /= num;
    vector<int> b(n);
    rep(i, n - 1) b[i] = a[i + 1] - a[i] - sum;
    b[n - 1] = a[0] - a[n - 1] - sum;
    bool ok = true;
    rep(i, n) if (b[i] > 0 || b[i] % n != 0) ok = false;
    cout << (ok ? "YES" : "NO") << endl;
}