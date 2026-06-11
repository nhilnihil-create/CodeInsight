#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
ll INF = (1LL << 60) - 1;
int MOD = 1e9+7;
ll calc(ll H, ll W){
    ll mini = INF;
    rep(h,1,H){
        ll s1 = h * W;
        ll s2 = (H-h) * (W/2);
        ll s3 = (H-h) * ((W+1)/2);

        mini = min(mini, max({s1, s2, s3}) - min({s1, s2, s3}) );
        if(h==H-1)continue;
        s2 = (H-h)/2 * W;
        s3 = (H-h+1)/2 * W;
        mini = min(mini, max({s1, s2, s3}) - min({s1, s2, s3}));
    }
    
    return mini;
}
main(){
    ll H,W;
    cin >> H >> W;
    if (H % 3 == 0 || W % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << min(calc(H,W), calc(W,H)) << endl;
}