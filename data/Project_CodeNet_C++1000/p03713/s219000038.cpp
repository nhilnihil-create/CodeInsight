#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<ll, ll>;

P sub(ll h, ll w){
    if(h % 2 == 0 || w % 2 == 0) return P(h*w/2, h*w/2);
    if(h > w) swap(h, w);
    ll l = w / 2;
    return P(h * l, h * (w - l));
}

int main(){
    ll H, W;
    cin >> H >> W;
    ll ans = H * W;
    for(ll h = 1; h <= H - 1; ++h){
        vector<ll> a(3);
        a[0] = h * W;
        auto p = sub(H - h, W);
        a[1] = p.first; a[2] = p.second;
        sort(ALL(a));
        ans = min(ans, a[2] - a[0]);
    }
    for(ll w = 1; w <= W - 1; ++w){
        vector<ll> a(3);
        a[0] = w * H;
        auto p = sub(W - w, H);
        a[1] = p.first; a[2] = p.second;
        sort(ALL(a));
        ans = min(ans, a[2] - a[0]);
    }
    cout << ans << endl;
}