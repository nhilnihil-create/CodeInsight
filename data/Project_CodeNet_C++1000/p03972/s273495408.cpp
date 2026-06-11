#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll H, W, ans=0, tmp=0;
vector<ll> Ws, Hs, S;

signed main(){
    cin >> W >> H;
    for(int i=0;i<W;i++) {
        ll a;
        cin >> a;
        Ws.push_back(a);
        ans += a*(H+1);
    }
    for(int i=0;i<H;i++) {
        ll a;
        cin >> a;
        Hs.push_back(a);
        ans += a*(W+1);
    }
    //cout << ans << endl;
    sort(Ws.begin(), Ws.end());
    S = Ws;
    for(int i=1;i<W;i++) {
        S[W-1-i] += S[W-i];
    }
    for(int i=0;i<H;i++) {
        ll id = lower_bound(Ws.begin(), Ws.end(), Hs[i])-Ws.begin();
        //cout << Hs[i]*id << " " << S[i] << endl;
        ans -= Hs[i]*id;
        if(id<W) ans -= S[id];
    }
    cout << ans << endl;
    return 0;
}