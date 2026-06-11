// 要復習
// 長方形の分割

#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int64_t H, W;
    cin >> H >> W;
    if (H % 3 == 0 || W % 3 == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int64_t ans = H * W;
        for (int i = 0; i < 2; i++)
        {
            for (int64_t j = 1; j < W; j++)
            {
                int64_t s1 = j * H;
                int64_t s2 = (H / 2) * (W - j);
                int64_t s3 = ((H + 1) / 2) * (W - j);
                int64_t mx = max({s1, s2, s3});
                int64_t mn = min({s1, s2, s3});
                ans = min(ans, mx - mn);

                s2 = (W - j) / 2 * H;
                s3 = (W - j + 1) / 2 * H;
                mx = max({s1, s2, s3});
                mn = min({s1, s2, s3});
                ans = min(ans, mx - mn);
            }
            swap(H, W);
        }
        cout << ans << endl;
    }
}
