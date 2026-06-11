#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll slice_area(ll H, ll W) {
    ll res = H*W;
    if(W <= 2) return res;
    for(ll i = W/3; (i+1)*2 < W; ++i) {
        ll S1 = H*i, S2 = H*(W - 2*i);
        res = min(res, abs(S1 - S2));
    }
    return res;
}

ll T_area(ll H, ll W) {
    ll res = H*W;
    for(ll i = 1; i < W; ++i) {
        ll  S1 = H*i,
            S2 = H/2 * (W - i),
            S3 = (H - H/2)*(W - i);
        ll  mx = max(S1, max(S2, S3)),
            mn = min(S1, min(S2, S3));
        res = min(res, abs(mx - mn));
    }
    return res;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    if(H%3 == 0 || W%3 == 0) { cout << 0 << endl; return 0; }

    ll res = H * W;
    res = min(res, slice_area(H, W));
    res = min(res, slice_area(W, H));
    res = min(res, T_area(H, W));
    res = min(res, T_area(W, H));
    
    cout << res << endl;

    return 0;
}
