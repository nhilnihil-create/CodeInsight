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
const int inf = 1<<31;
const ll inf_l = 1LL<<61;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    vint p(n);
    rep(i,n) cin >> p[i];
    vint ans_a(n), ans_b(n);
    rep(i,n) {
        ans_a[i] = n * (i+1);
        ans_b[i] = n * (n-i);
    }
    rep(i,n) {
        ans_b[p[i]-1] += i;
    }
    rep(i,n) printf("%d%s",ans_a[i],i==n-1?"\n":" ");
    rep(i,n) printf("%d%s",ans_b[i],i==n-1?"\n":" ");
}