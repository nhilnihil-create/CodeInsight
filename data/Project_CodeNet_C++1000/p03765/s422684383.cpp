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
    vint sum_s_a(n_s+1,0), sum_s_b(n_s+1,0);
    vint sum_t_a(n_t+1,0), sum_t_b(n_t+1,0);
    rep(i,n_s) {
        sum_s_a[i+1] += sum_s_a[i];
        sum_s_b[i+1] += sum_s_b[i];
        if (s[i] == 'A') sum_s_a[i+1]++;
        if (s[i] == 'B') sum_s_b[i+1]++;
    }
    rep(i,n_t) {
        sum_t_a[i+1] += sum_t_a[i];
        sum_t_b[i+1] += sum_t_b[i];
        if (t[i] == 'A') sum_t_a[i+1]++;
        if (t[i] == 'B') sum_t_b[i+1]++;
    }
    int q; cin >> q;
    rep(i,q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = (sum_s_a[b]-sum_s_a[a-1]) - (sum_s_b[b]-sum_s_b[a-1]);
        int y = (sum_t_a[d]-sum_t_a[c-1]) - (sum_t_b[d]-sum_t_b[c-1]);
        if (abs(x-y) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}