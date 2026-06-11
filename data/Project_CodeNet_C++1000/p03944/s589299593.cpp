#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n), a(n);
    rep(i, n) cin >> x[i] >> y[i] >> a[i];

    int xx = 0, yy = 0;
    rep(i, n)
    {
        if (a[i] == 1)
        {
            xx = max(x[i], xx);
        }
        else if (a[i] == 2)
        {
            w = min(w, x[i]);
        }
        else if (a[i] == 3)
        {
            yy = max(y[i], yy);
        }
        else
        {
            h = min(y[i], h);
        }
    }
    int ans = 0;
    if (h > yy && w > xx)
    {
        ans = (h - yy) * (w - xx);
    }

    cout << ans << endl;
    return (0);
}
