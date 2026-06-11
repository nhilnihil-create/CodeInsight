#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    ll h, w;
    cin >> h >> w;
    if (h%3 == 0 || w%3 == 0){
        cout << 0 << endl;
        return 0;
    }
    int d[3] = {-1, 0, 1};

    ll ans = h * w;
    rep(y, 3){
        rep(x, 3){
            ll p = h / 3 + d[y];
            ll q = w / 2 + d[x];
            ll u = h / 2 + d[y];
            ll v = w / 3 + d[x];
            ll smx1 = max({p * w, (h-p)*q, (h-p)*(w-q)});
            ll smn1 = min({p * w, (h-p)*q, (h-p)*(w-q)});
            ll smx2 = max({v * h, (w-v)*u, (w-v)*(h-u)});
            ll smn2 = min({v * h, (w-v)*u, (w-v)*(h-u)});
            ans = min({ans, smx1 - smn1, smx2 - smn2});
        }
    }

    rep(a, 3){
        rep(b, 3){
            ll p = h / 3 + d[a];
            ll q = h / 3 * 2 + d[b];
            ll u = w / 3 + d[a];
            ll v = w / 3 * 2 + d[b];
            ll smx1 = max({p * w, (q-p) * w, (h-q) * w});
            ll smn1 = min({p * w, (q-p) * w, (h-q) * w});
            ll smx2 = max({u * h, (v-u) * h, (w-v) * h});
            ll smn2 = min({u * h, (v-u) * h, (w-v) * h});
            ans = min({ans, smx1 - smn1, smx2 - smn2});
        }
    }

    cout << ans << endl;
    return 0;
}