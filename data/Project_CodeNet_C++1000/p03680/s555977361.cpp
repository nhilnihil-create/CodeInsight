#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> b(n, false);
    rep(i, n) cin >> a[i], --a[i];

    int p = 0;
    b[0] = true;
    int ans = 0;
    while (1)
    {
        ++ans;
        p = a[p];
        if (p == 1)
        {
            cout << ans << endl;
            return 0;
        }
        if (b[p])
        {
            cout << -1 << endl;
            return 0;
        }
        b[p] = true;
    }
}