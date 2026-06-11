#define _GLIBCXX_DEBUG
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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> c(9);
    rep(i, n)
    {
        int r = a[i] / 400;
        if (r >= 9)
            r = 8;
        c[r]++;
    }
    int cnt = 0;
    rep(i, 8) if (c[i] > 0) cnt++;
    int mn = cnt;
    if (mn == 0)
        mn++;
    int mx = cnt + c[8];
    printf("%d %d\n", mn, mx);
}

int main()
{
    solve();
    return 0;
}