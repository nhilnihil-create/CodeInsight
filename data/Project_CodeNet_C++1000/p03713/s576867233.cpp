#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll H, W;
    cin >> H >> W;
    ll ans = LONG_MAX;

    for (ll h = 1; h <= H - 1; ++h)
    {
        ll s1, s2, s3, sMax, sMin;
        s1 = h * W;

        s2 = (H - h) * (W / 2);
        s3 = (H - h) * (W - W / 2);
        sMax = max(s1, max(s2, s3));
        sMin = min(s1, min(s2, s3));
        ans = min(ans, sMax -sMin);

        s2 = ((H - h) / 2) * W;
        s3 = ((H - h) - ((H - h) / 2)) * W;
        sMax = max(s1, max(s2, s3));
        sMin = min(s1, min(s2, s3));
        ans = min(ans, sMax -sMin);
    }

    for (ll w = 1; w <= W - 1; ++w)
    {
        ll s1, s2, s3, sMax, sMin;
        s1 = H * w;

        s2 = (H / 2) * (W - w);
        s3 = (H - H / 2) * (W - w);
        sMax = max(s1, max(s2, s3));
        sMin = min(s1, min(s2, s3));
        ans = min(ans, sMax - sMin);

        s2 = H * ((W - w) / 2);
        s3 = H * ((W - w) - ((W - w) / 2));
        sMax = max(s1, max(s2, s3));
        sMin = min(s1, min(s2, s3));
        ans = min(ans, sMax - sMin);
    }

    cout << ans << endl;
}
