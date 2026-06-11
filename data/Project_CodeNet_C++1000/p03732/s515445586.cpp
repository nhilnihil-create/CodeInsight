#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

int main(){
    int n, lim;
    cin >> n >> lim;
    vector<vector<ll>> a(4, vector<ll>(1, 0));
    ll minw;
    rep(i, n){
        ll w, v;
        cin >> w >> v;
        if(i == 0) minw = w;
        a[w - minw].push_back(v);
    }

    rep(i, 4){
        if(a[i].size() != 0) sort(rall(a[i]));
    }

    ll ans = 0;
    rep(i, a[0].size()){
        rep(j, a[1].size()){
            rep(k, a[2].size()){
                rep(l, a[3].size()){
                    ll w = (minw)*i + (minw+1)*j + (minw+2)*k + (minw+3)*l;
                    ll v = 0;
                    if(w <= lim){
                        rep(idx, i) v += a[0][idx];
                        rep(idx, j) v += a[1][idx];
                        rep(idx, k) v += a[2][idx];
                        rep(idx, l) v += a[3][idx];
                    }
                    ans = max(ans, v);
                }
            }
        }
    }

    cout << ans << endl;
}
