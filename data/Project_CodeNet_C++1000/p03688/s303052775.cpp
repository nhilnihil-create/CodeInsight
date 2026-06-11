#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];
    bool ans = false;
    int mx = *max_element(all(a));
    int mn = *min_element(all(a));
    if (mx - mn == 1) {
        int ct_mx = 0, ct_mn = 0;
        rep(i,n) {
            if (a[i] == mx) ct_mx++;
            else ct_mn++;
        }
        if (ct_mn < mx && n + ct_mn >= 2 * mx) ans = true;
    }
    if (mx - mn == 0) {
        if (mx + 1 == n || n >= 2 * mx) ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}