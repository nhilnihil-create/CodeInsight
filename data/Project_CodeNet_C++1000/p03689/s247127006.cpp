/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    ll H,W,h,w;
    cin >> H >> W >> h >> w;
    if(H % h == 0 && W % w == 0){
        print("No");
        return 0;
    }
    ll res[510][510] = {};
    rep(i,0,H){
        rep(j,0,W){
            res[i][j] = 1000;
        }
    }
    for(ll hi = h-1; hi < H; hi += h){
        for(ll wi = w-1; wi < W; wi += w){
            res[hi][wi] = -1000 * (h*w - 1) - 1;
        }
    }
    print("Yes");
    rep(i,0,H){
        rep(j,0,W){
            cout << res[i][j] << " \n"[j==W-1];
        }
    }
    
}