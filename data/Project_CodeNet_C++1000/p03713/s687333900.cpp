#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

vector<vector<ll>> g(100010); 
vector<ll> dist(100010);

int main(){
    ll h, w;
    cin >> h >> w;

    if(h%3 == 0 || w%3 == 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = min(h, w);

    ll w_1, w_2;
    if(w&1){
        w_1 = w/2;
        w_2 = w/2 + 1;
    }
    else {
        w_1 = w_2 = w/2;
    }

    rep(i, h+1){
        ll s_max = max(i*w, (h-i)*w_2);
        ll s_min = min(i*w, (h-i)*w_1);

        ans = min(ans, s_max-s_min);
    }

    ll h_1, h_2;
    if(h&1){
        h_1 = h/2;
        h_2 = h/2 + 1;
    }
    else {
        h_1 = h_2 = h/2;
    }

    rep(i, w+1){
        ll s_max = max(i*h, (w-i)*h_2);
        ll s_min = min(i*h, (w-i)*h_1);

        ans = min(ans, s_max-s_min);
    }

    cout << ans << endl;
}