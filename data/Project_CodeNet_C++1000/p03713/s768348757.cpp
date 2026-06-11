#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll H, W; cin >> H >> W;
    if (H % 3 == 0 || W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = inf;
    for (size_t i = 1; i < H; i++)
    {
        ll a = W * i;

        ll b = (W / 2) * (H - i), c = (W / 2) * (H - i);
        if (W % 2 == 1) c += (H - i);

        ll num = abs(max(max(a, b), c) - min(min(a, b), c));
        ans = min(ans, num);

        ll hh = H - i;
        b = (hh / 2) * W, c = (hh / 2) * W;
        if (hh % 2) c += W;
        num = abs(max(max(a, b), c) - min(min(a, b), c));
        ans = min(ans, num);
    }

    for (size_t i = 1; i < W; i++)
    {
        ll a = H * i;
        ll b = (H / 2) * (W - i), c = (H / 2) * (W - i);
        if (H % 2) c += (W - i);

        ll num = abs(max(max(a, b), c) - min(min(a, b), c));
        ans = min(ans, num);

        ll ww = W - i;
        b = (ww / 2) * H, c = (ww / 2) * H;
        if (ww % 2) c += H;
        num = abs(max(max(a, b), c) - min(min(a, b), c));
        ans = min(ans, num);        
    }
    cout << ans << endl;

    return 0;
}