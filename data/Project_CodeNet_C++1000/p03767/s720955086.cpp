// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    n = 3 * n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    ll ans = 0;
    for (int i = 1; i <= n * 2 / 3; i += 2)
    {
        ans += a[i];
    }
    cout << ans << endl;
}

int main()
{
    // srand((unsigned)time(NULL));
    // int t = clock();
    solve();
    // double et = 1.0 * (clock() - t) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}