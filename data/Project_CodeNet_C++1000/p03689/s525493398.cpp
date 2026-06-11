//In The Name of Beauty
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define IB std::ios::sync_with_stdio(0);
#define pb(x) push_back(x);
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define F first
#define S second
ll const MAXN = 1e5 + 8;
ll const INF  = 1e9;
ll const delta = 1000000007;
int main()
{
    IB;
    cin.tie(0);
    cout.tie(0);
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    ll x = (H / h) * (W / w);
    ll l = 0 , r = INF, mid = (l + r) / 2;
    while(r - l > 1){
        if((H * W - x) * mid > x * INF)r = mid;
        else l = mid;
        mid = (l + r) / 2;
    }
    ll t;
    if((H * W - x) * l > x * INF)t = l;
    else if((H * W - x) * r > x * INF)t = r;
    else return cout << "No",0;
    if((h * w - 1) * t > INF)return cout << "No",0;
    cout << "Yes" << endl;
    for(ll i = 0;i < H;i++){
        for(ll j = 0;j < W;j++){
            if((i % h == h - 1) && (j % w == w - 1))cout << -INF << " ";
            else cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}
//Written by M_H_H_7
