#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n), a(n);
    rep(i, n) cin >> x[i] >> y[i] >> a[i];

    int xmi = 0, ymi = 0, xma = w, yma = h;
    rep(i, n)
    {
        if (a[i] == 1)
        {
            xmi = max(xmi, x[i]);
        }
        else if (a[i] == 2)
        {
            xma = min(xma, x[i]);
        }
        else if (a[i] == 3)
        {
            ymi = max(ymi, y[i]);
        }
        else
        {
            yma = min(yma, y[i]);
        }
    }
    int ans=0;
    if ( xma>xmi && yma > ymi)
    {
        ans = (xma - xmi) * (yma - ymi);
    }
    cout << ans << endl;

    return 0;
}
