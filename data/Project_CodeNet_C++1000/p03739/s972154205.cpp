#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,ll>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 2*1e5;
const int mod = 1e9+7;

int main() {
    int n; cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];
    vll c(n);
    c[0] = a[0];
    REP(i,n) c[i] = c[i-1] + a[i];
    vll c_pos = c;
    ll accum = 0;
    ll ans_pos = 0;
    // はじめが正
    rep(i,n) {
        if (i&1) {
            c_pos[i] += accum;
            if (c_pos[i] >= 0) {
                ans_pos += c_pos[i]+1;
                accum -= c_pos[i]+1;
            }
        }
        if (!(i&1)) {
            c_pos[i] += accum;
            if (c_pos[i] <= 0) {
                ans_pos += -c_pos[i]+1;
                accum += -c_pos[i]+1;
            }
        }
    }
    // はじめが負
    vll c_neg = c;
    accum = 0;
    ll ans_neg = 0;
    rep(i,n) {
        if (i&1) {
            c_neg[i] += accum;
            if (c_neg[i] <= 0) {
                ans_neg += -c_neg[i]+1;
                accum += -c_neg[i]+1;
            }
        }
        if (!(i&1)) {
            c_neg[i] += accum;
            if (c_neg[i] >= 0) {
                ans_neg += c_neg[i]+1;
                accum -= c_neg[i]+1;
            }
        }
    }
    cout << min(ans_pos,ans_neg) << endl;
}