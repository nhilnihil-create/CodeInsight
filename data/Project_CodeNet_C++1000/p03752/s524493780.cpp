#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = INT64_MAX;
    for (int bit = (1 << (k - 1)) - 1; bit < (1 << n); ++bit)
    {
        if (!(bit & 1))
            continue;
        int count = 0;
        rep(i, n) if (bit & (1 << i)) count++;
        if (count < k)
            continue;

        ll min_height = a[0];
        ll sum = 0;
        for (int i = 1; i < n; ++i)
        {
            if (bit & (1 << i))
            {
                if (a[i] <= min_height)
                    min_height += 1;
                else
                    min_height = a[i];
                sum += min_height - a[i];
            }
            else if (a[i] >= min_height)
            {
                sum = INT64_MAX;
                break;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}