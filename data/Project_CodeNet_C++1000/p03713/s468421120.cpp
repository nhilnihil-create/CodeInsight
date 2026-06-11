#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using ll = long long;
using namespace std;

int main() {
    ll H,W; cin >> H >> W;

    ll ans = H * W;
    
    ll s[3];

    for(int i=0;i<2;i++){
        for(ll h=1;h<H;h++){
            //縦割り
            s[0] = h * W;
            s[1] = (H-h) * (W / 2);
            s[2] = H * W - (s[0] + s[1]);
            sort(begin(s),end(s));
            ans = min(ans, s[2] - s[0]);

            //横割り
            s[0] = h * W;
            s[1] = ((H - h) / 2) * W;
            s[2] = (H * W) - (s[0] + s[1]);
            sort(begin(s),end(s));
            ans = min(ans, s[2] - s[0]);

        }
        swap(H,W);
    }
    cout << ans << endl;

    return 0;
}



