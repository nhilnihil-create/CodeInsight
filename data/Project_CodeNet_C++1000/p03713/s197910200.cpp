#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    ll H, W;
    cin >> H >> W;
    ll ans = 1 << 30;
    ll cnt = 0;
    while (cnt < 2)
    {
        if (H > 2)
        {
            if (H % 3 == 0)
            {
                ans = min(ans, 0ll);
            }
            else
            {
                ans = min(ans, W);
            }
        }
        int mid = H / 2;
        for (int i = 1; i < W; i++)
        {
            ll s1 = H * i;
            ll s2 = mid * (W - i);
            ll s3 = (mid + H % 2) * (W - i);
            ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        }
        cnt++;
        swap(H, W);
    }
    cout << ans << endl;
    return 0;
}