#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll W, H, N;
    cin >> W >> H >> N;
    ll lm[5] = {0, 0, W, 0, H};
    rep(i, 0, N){
        ll x, y, a;
        cin >> x >> y >> a;
        if(a == 1){
            lm[a] = max(lm[a], x);
        }else if(a == 2){
            lm[a] = min(lm[a], x);
        }else if(a == 3){
            lm[a] = max(lm[a], y);
        }else{
            lm[a] = min(lm[a], y);
        }
    }
    if(lm[1] > lm[2] || lm[3] > lm[4]){
        cout << 0 << endl;
    }else{
        ll ans = H * W;
        ans -= lm[1] * H + (W - lm[2]) * H;
        ans -= lm[3] * W + (H - lm[4]) * W;
        ans += lm[1] * lm[3] + lm[1] * (H - lm[4]);
        ans += (W - lm[2]) * lm[3] + (W - lm[2]) * (H - lm[4]);
        cout << ans << endl;
    }
    return 0;
}