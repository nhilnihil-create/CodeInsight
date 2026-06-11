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

int solve(int a, int b)
{
    if (a == 0)
        return 0;
    if (a == b)
        return a;
    if (a > b)
        return solve(b, a);
    if (a == 1)
        return 2 * (b - 1) + 1;
    if (b % a == 0)
        return a * solve(1, b / a);
    return 2 * (b / a) * a + solve(a, b % a);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    cout << n + solve(n - x, x) << endl;
}