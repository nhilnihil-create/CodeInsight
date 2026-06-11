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
const int inf = 1e9+10;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    string s, t; cin >> s >> t;
    int n_s = s.size(), n_t = t.size();
    auto f = [](string x) -> vint {
        vint res(x.size()+1,0);
        rep(i,x.size()) {
            res[i+1] += res[i] + (x[i]=='A'?1:2);   
        }
        return res;
    };
    vint sum_s = f(s), sum_t = f(t);
    int q; cin >> q;
    rep(i,q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (abs((sum_s[b]-sum_s[a-1])-(sum_t[d]-sum_t[c-1])) % 3 == 0) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
}