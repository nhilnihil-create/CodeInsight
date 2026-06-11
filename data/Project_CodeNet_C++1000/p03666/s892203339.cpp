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

int n, a, b, c, d;

bool dfs(ll sum = 0, int cur = 0) {
    if (cur == n-1) {
        if (sum == b-a) return true;
        else return false;
    }
    bool res = false;
    for (int x = c; x <= d; x++) {
        if (dfs(sum+x,cur+1)) res = true;
        if (dfs(sum-x,cur+1)) res = true;
    }
    return res;
}

int main() {
    cin >> n >> a >> b >> c >> d;
    n--;
    bool ok = false;
    for (int x = 0; x <= n; x++) {
        ll lb = (ll)x*(c+d)-(ll)n*d;
        ll ub = (ll)x*(c+d)-(ll)n*c;
        if (lb <= b-a && b-a <= ub) ok = true;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}