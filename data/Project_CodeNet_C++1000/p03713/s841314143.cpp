#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll H,W;
    cin >> H >> W;
    if (H % 3 == 0 || W % 3 == 0){
        cout << 0 << endl;
    }
    else{
        ll ans = min(H,W);
        for(ll i = 1; i <= H - 1; i++){
            ll p1 = i * W;
            if (W % 2 == 0){
                ll p2 = (H - i) * W / 2;
                ans = min(ans, max(p1 - p2, p2 - p1));
            }
            else{
                ll p2 = (H - i) * (W / 2);
                ll p3 = (H - i) * W - p2;
                ll s_max = max(p1,max(p2,p3));
                ll s_min = min(p1,min(p2,p3));
                ans = min(ans, s_max - s_min);
                
            }
        }
        for(ll i = 1; i <= W - 1; i++){
            ll p4 = i * H;
            if (H % 2 == 0){
                ll p5 = (W - i) * H / 2;
                ans = min(ans, max(p4 - p5, p5 - p4));
            }
            else{
                ll p5 = (W - i) * (H / 2);
                ll p6 = (W - i) * H - p5;
                ll s_max = max(p4,max(p5,p6));
                ll s_min = min(p4,min(p5,p6));
                ans = min(ans, s_max - s_min);
            }
        }
        cout << ans << endl;
    }
}
