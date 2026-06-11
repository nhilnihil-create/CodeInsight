#include <iostream>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll h, w;
    cin >> h >> w;
    ll ans = h * w;
    rep(_, 2){
        for(int i = 1; i < h; i++){
            ll s1 = i * w;
            ll s2 = (h - i) / 2 * w;
            ll s3 = h * w - s1 - s2;
            ll smax = max(s1, max(s2, s3));
            ll smin = min(s1, min(s2, s3));
            ans = min(ans, smax - smin);

            s2 = (h - i) * (w / 2);
            s3 = h * w - s1 - s2;
            smax = max(s1, max(s2, s3));
            smin = min(s1, min(s2, s3));
            ans = min(ans, smax - smin);
        }
        swap(h, w);
    }
    cout << ans << endl;
    return 0;
}