#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll H, W; cin >> H >> W;
    if(H % 3 == 0 || W % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = min(H, W);
    for (int i = 1; i < H; i++){
        ll s1 = i*W;
        ll s2, s3, sa;
        if(W % 2 == 0){
            s2 = (H-i) * (W/2);
            sa = abs(s1-s2);
        } else {
            s2 = (H-i) * (W/2 + 1);
            s3 = (H-i) * (W/2);
            sa = max(abs(s1-s2), abs(s1-s3));
            sa = max(sa, abs(s2-s3));
        }
        ans = min(ans, sa);
    }

    for (int i = 1; i < W; i++){
        ll s1 = i*H;
        ll s2, s3, sa;
        if(H % 2 == 0){
            s2 = (W-i) * (H/2);
            sa = abs(s1-s2);
        } else {
            s2 = (W-i) * (H/2 + 1);
            s3 = (W-i) * (H/2);
            sa = max(abs(s1-s2), abs(s1-s3));
            sa = max(sa, abs(s2-s3));
        }
        ans = min(ans, sa);
    }

    cout << ans << endl;

    return 0;
}