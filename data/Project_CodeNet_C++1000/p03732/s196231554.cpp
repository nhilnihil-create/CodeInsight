#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
typedef vector<vector<P>> vvP;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n, W;
    cin >> n >> W;
 
    ll w0, v0;
    cin >> w0 >> v0;
 
    vl weight(n), value(n);
    vvl x(4);  // x[i][j] : 重さw0+iの品物でj番目に高い価値
    weight[0] = w0, value[0] = v0;
    x[0].pb(v0);
    exrep(i, 1, n-1) {
        cin >> weight[i] >> value[i];
        x[weight[i] - w0].pb(value[i]);
    }
 
    rep(i, 4) {
        sort(rall(x[i]));
    }
 
    vl rui0(x[0].size()+1);  // rui0[i+1] : x[0][0]からx[0][i]までの和
    rep(i, x[0].size()) {
        rui0[i+1] = rui0[i] + x[0][i];
    }
    vl rui1(x[1].size()+1);  // rui1[i+1] : x[1][0]からx[1][i]までの和
    rep(i, x[1].size()) {
        rui1[i+1] = rui1[i] + x[1][i];
    }
    vl rui2(x[2].size()+1);  // rui2[i+1] : x[2][0]からx[2][i]までの和
    rep(i, x[2].size()) {
        rui2[i+1] = rui2[i] + x[2][i];
    }
    vl rui3(x[3].size()+1);  // rui3[i+1] : x[3][0]からx[3][i]までの和
    rep(i, x[3].size()) {
        rui3[i+1] = rui3[i] + x[3][i];
    }
 
    ll ans = 0;
    exrep(a, 0, x[0].size()) {
        exrep(b, 0, x[1].size()) {
            exrep(c, 0, x[2].size()) {
                exrep(d, 0, x[3].size()) {
                    ll sumW = w0*a + (w0+1)*b + (w0+2)*c + (w0+3)*d;
                    if(sumW <= W) {
                        chmax(ans, rui0[a] + rui1[b] + rui2[c] + rui3[d]);
                    }
                }
            }
        }
    }
 
    out(ans);
    re0;
}