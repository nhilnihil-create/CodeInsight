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

struct pascal_comb {
    vector<vector<long long>> dat;
    pascal_comb(int s) : dat(s+1,vector<long long>(s+1)) {
        rep(i,s+1) {
            dat[i][0] = 1;
            dat[i][i] = 1;
        }
        for (int k = 1; k < s+1; k++) {
            for (int j = 1; j < k; j++) {
                dat[k][j] = dat[k-1][j-1] + dat[k-1][j];
            }
        }
    }
    long long operator() (int a, int b) {
        if (b < 0 || a < b) return 0;
        return dat[a][b];
    }
};

int main() {
    int n, p; cin >> n >> p;
    int ct_0 = 0, ct_1 = 0;
    rep(i,n) {
        int x; cin >> x;
        if (x % 2 == 0) ct_0++;
        else ct_1++;
    }
    pascal_comb com(50);
    ll ans = 0;
    if (p == 0) {
        for (int a = 0; a <= ct_1; a += 2) {
            ans += com(ct_1,a) * pow(2,ct_0);
        }
    } else {
        for (int a = 1; a <= ct_1; a += 2) {
            ans += com(ct_1,a) * pow(2,ct_0);
        }
    }
    cout << ans << endl;
}