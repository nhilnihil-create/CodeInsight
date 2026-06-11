#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int W, H, N;
    cin >> W >> H >> N;
    int w_min = 0, w_max = W;
    int h_min = 0, h_max = H;
    rep(i, N){
        int x, y, a;
        cin >> x >> y >> a;
        if(a==1) w_min = max(x, w_min);
        else if(a==2) w_max = min(x, w_max);
        else if(a==3) h_min = max(y, h_min);
        else h_max = min(y, h_max);
    }
    if(h_max-h_min<1||w_max-w_min<1) cout << 0 << endl;
    else{
        int ans = (h_max-h_min)*(w_max-w_min);
        cout << ans << endl;
    }
    return 0;
}
