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

int n;
vector<int> a;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int N = 3 * n;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<int> l(n + 1), r(n + 1);
    priority_queue<int, vector<int>, greater<int>> que1;
    int sum = 0;
    rep(i, n)
    {
        sum += a[i];
        que1.push(a[i]);
    }
    l[0] = sum;
    rep(i, n)
    {
        int x = a[i + n], y = que1.top();
        if (x > y)
        {
            sum = sum + x - y;
            que1.pop();
            que1.push(x);
        }
        l[i + 1] = sum;
    }

    sum = 0;
    priority_queue<int> que2;
    rep(i, n)
    {
        sum += a[N - i - 1];
        que2.push(a[N - i - 1]);
    }
    r[n] = sum;
    rep(i, n)
    {
        int x = a[2 * n - i - 1], y = que2.top();
        if (x < y)
        {
            sum = sum + x - y;
            que2.pop();
            que2.push(x);
        }
        r[n - i - 1] = sum;
    }

    int ans = -INF;
    rep(i, n + 1) ans = max(ans, l[i] - r[i]);
    cout << ans << endl;
}