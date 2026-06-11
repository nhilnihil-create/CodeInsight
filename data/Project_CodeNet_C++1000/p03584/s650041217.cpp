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
const int inf = 1<<30;
const ll inf_l = 1LL<<61;
const int MAX = 1e5;

int main() {
    int n, K; cin >> n >> K;
    vint a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    set<int> zeros;
    ll ans = -1;
    for (int i = 30; i >= 0; i--) {
        ll sum = 0;
        if (i == 0) {
            if (!(K>>i&1)) zeros.insert(0);
            rep(j,n) {
                bool ok = true;
                rep(k,30) if (a[j]>>k&1 && zeros.count(k)) ok = false; 
                if (ok) sum += b[j];
            }
        } else if (K >> i & 1) {
            rep(j,n) {
                bool ok = true;
                if (a[j] >> i & 1) ok = false;
                rep(k,30) if (a[j]>>k&1 && zeros.count(k)) ok = false; 
                if (ok) sum += b[j];
            }
        } else zeros.insert(i);
        ans = max(ans,sum);
    }
    cout << ans << endl;
}