#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, h, w;
    cin >> w >> h >> n;
    ll ux = w, bx = 0, uy = h, by = 0;
    rep(i, 0, n){
        ll x, y, a;
        cin >> x >> y >> a;
        if(a == 1){
            bx = max(bx, x);
        }
        if(a == 2){
            ux = min(ux, x);
        }
        if(a == 3){
            by = max(by, y);
        }
        if(a == 4){
            uy = min(uy, y);
        }
        // cerr << bx << "," << ux << endl;
        // cerr << by << "," << uy << endl;
    }
    ll ans;
    if(bx > ux || by > uy) ans = 0;
    else ans = (ux - bx) * (uy - by);
    cout << ans << endl;
    return 0;
}