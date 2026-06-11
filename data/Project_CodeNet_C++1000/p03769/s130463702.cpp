#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    ll N;
    cin >> N;
    ll comb[41][41];
    rep(i, 41) rep(j, 41) comb[i][j] = 0;
    comb[0][0] = 1;
    rep(i, 40){
        rep(j, i+1){
            comb[i+1][j] += comb[i][j];
            comb[i+1][j+1] += comb[i][j];
        }
    }
    int n;
    rep3(i, 39, 1){
        if(N >= (1LL<<i)-1) {n = i; break;}
    }
    N -= (1LL<<n)-1;
    n++;
    int now = 2;
    vector<int> res[n];
    rep3(i, (n-1)/2, 1){
        int cnt = N/comb[n][i], memo = now;
        rep(j, cnt){
            res[0].pb(now), res[i].pb(2*memo+cnt-1-now);
            now++;
        }
        N %= comb[n][i];
    }
    vector<int> ans;
    rep(i, n){
        for(auto &e: res[i]) ans.pb(e);
        ans.pb(1);
    }
    rep3(i, 39, 1){
        ll a = (1LL<<i)-1;
        int cnt = N/a;
        rep(j, cnt){
            rep(k, i+1) ans.pb(now);
            now++;
        }
        N %= a;
    }
    cout << sz(ans) << endl;
    for(auto &e: ans) cout << e << ' '; cout << endl;
}