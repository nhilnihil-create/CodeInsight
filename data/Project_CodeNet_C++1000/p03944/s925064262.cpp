#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    int p1 = 0, p2 = w, p3 = 0, p4 = h;
    rep(i, n)
    {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1)
            p1 = max(p1, x);
        if (a == 2)
            p2 = min(p2, x);
        if (a == 3)
            p3 = max(p3, y);
        if (a == 4)
            p4 = min(p4, y);
    }
    int ans = max(p4 - p3, 0) * max(p2 - p1, 0);
    cout << ans << endl;
}