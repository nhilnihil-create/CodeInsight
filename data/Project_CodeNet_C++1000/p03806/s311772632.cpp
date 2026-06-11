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
const int MAX = 20000;

int main() {
    int n, ma, mb; cin >> n >> ma >> mb;
    vint a_l, a_r, b_l, b_r, c_l, c_r;
    rep(i,n) {
        int a, b, c; cin >> a >> b >> c;
        if (i < n / 2) {
            a_l.push_back(a);
            b_l.push_back(b);
            c_l.push_back(c);
        } else {
            a_r.push_back(a);
            b_r.push_back(b);
            c_r.push_back(c);
        }
    }
    int n_l = a_l.size();
    int n_r = a_r.size();
    map<int,int> mp;
    int ans = inf;
    rep(i,1<<(n_l)) {
        int weight = 0, value = 0;
        rep(j,n_l) {
            if (i >> j & 1) {
                weight += ma * b_l[j] - mb * a_l[j];
                value += c_l[j];
            }
        }
        if (weight == 0 && value != 0) chmin(ans, value);
        if (!mp.count(weight)) mp[weight] = value;
        else if (weight != 0) chmin(mp[weight], value);
    }
    rep(i,1<<(n_r)) {
        int weight = 0, value = 0;
        rep(j,n_r) {
            if (i >> j & 1) {
                weight += mb * a_r[j] - ma * b_r[j];
                value += c_r[j];
            }
        }
        if (!mp.count(weight)) continue;
        if (weight == 0 && value != 0) chmin(ans, value);
        if (weight != 0) chmin(ans, mp[weight] + value);
    }
    printf("%d\n", ans == inf ? -1 : ans);
}