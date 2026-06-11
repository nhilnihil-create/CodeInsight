#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll H, W;
    cin >> H >> W;

    ll ans = 1e18;
    rep(h, 1, H){
        ll s1 = h * W, s2, s3, smx, smn, diff;
        // rest = W * (H-h);
        // H方向分割
        s2 = W * (ll)((H-h)/2);
        s3 = W * (ll)((H-h+1)/2);
        smx = max(s1, max(s2, s3));
        smn = min(s1, min(s2, s3));
        diff = smx - smn;
        ans = min(diff, ans);
        // W方向分割
        s2 = (H-h) * (ll)(W/2);
        s3 = (H-h) * (ll)((W+1)/2);
        smx = max(s1, max(s2, s3));
        smn = min(s1, min(s2, s3));
        diff = smx - smn;
        ans = min(diff, ans);
    }
    
    rep(w, 1, W){
        ll s1 = w * H, s2, s3, smx, smn, diff;
        // rest = W * (H-h);
        // W方向分割
        s2 = H * (ll)((W-w)/2);
        s3 = H * (ll)((W-w+1)/2);
        smx = max(s1, max(s2, s3));
        smn = min(s1, min(s2, s3));
        diff = smx - smn;
        ans = min(diff, ans);
        // W方向分割
        s2 = (W-w) * (ll)(H/2);
        s3 = (W-w) * (ll)((H+1)/2);
        smx = max(s1, max(s2, s3));
        smn = min(s1, min(s2, s3));
        diff = smx - smn;
        ans = min(diff, ans);
    }

    cout << ans << endl;
    return 0;
}