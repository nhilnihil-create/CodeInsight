#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
const ll MOD = 1e9 + 7;

int main() {
    ll N, W;
    cin >> N >> W;
    vector<vector<ll>> all(4,vector<ll>(N));
    ll w0;
    cin >> w0;
    ll v0;
    cin >> v0;
    all[0].push_back(v0);
    rep(i, N - 1) {
        ll x, y;
        cin >> x >> y;
        all[x - w0].push_back(y);
    }
    rep(i, 4) {
        sort(all[i]);
        riverse(all[i]);
    }
    vll ans;
    rep(i, all[0].size()) {
        rep(j, all[1].size()) {
            rep(k, all[2].size()) {
                rep(l,all[3].size()){
                    if (w0 * (i+j+k+l) + j+2*k+3*l <= W){
                        int value = 0;
                        rep(i1, i) value += all[0][i1];
                        rep(j1, j) value += all[1][j1];
                        rep(k1, k) value += all[2][k1];
                        rep(l1, l) value += all[3][l1];
                        ans.push_back(value);
                    }
                }
            }
        }
    }
    sort(ans);
    riverse(ans);
    cout << ans[0] << endl;
}