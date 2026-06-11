#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(ll i=0;i<N;++i)
typedef long long int ll;
typedef long double ld;
const ll INF = 1<<30;

int main(){
    ll H,W; cin >> H >> W;
    ll S = H*W;
    ll ans = INF;
    //SmaxとSminの横幅についての全探索をswap前後2回行う
    rep(w,W){
        ll S1 = H*w;
        //全体の長方形からS1を除いた長方形を２つに分ける方法を縦横でやる
        ll x1 = floor(((ld)(S - S1) / 2.0) / H);
        ll x2 = ceil(((ld)(S - S1) / 2.0) / H);
        ll S2 = H*x1, S3 = H*x2;
        ll Smax = max(max(S1,S2),S3), Smin = (min(min(S1,S2),S3));
        ans = min(ans , Smax-Smin);

        ll y1 = floor(((ld)(S - S1) / 2.0) / (W-w));
        ll y2 = ceil(((ld)(S - S1) / 2.0) / (W-w));
        S2 = (W-w)*y1, S3 = (W-w)*y2;
        Smax = max(max(S1,S2),S3), Smin = (min(min(S1,S2),S3));
        ans = min(ans , Smax-Smin);
    }
    swap(H,W);
    rep(w,W){
        ll S1 = H*w;
        //全体の長方形からS1を除いた長方形を２つに分ける方法を縦横でやる
        ll x1 = floor(((ld)(S - S1) / 2.0) / H);
        ll x2 = ceil(((ld)(S - S1) / 2.0) / H);
        ll S2 = H*x1, S3 = H*x2;
        ll Smax = max(max(S1,S2),S3), Smin = (min(min(S1,S2),S3));
        ans = min(ans , Smax-Smin);

        ll y1 = floor(((ld)(S - S1) / 2.0) / (W-w));
        ll y2 = ceil(((ld)(S - S1) / 2.0) / (W-w));
        S2 = (W-w)*y1, S3 = (W-w)*y2;
        Smax = max(max(S1,S2),S3), Smin = (min(min(S1,S2),S3));
        ans = min(ans , Smax-Smin);
    }
    cout << ans << endl;
}