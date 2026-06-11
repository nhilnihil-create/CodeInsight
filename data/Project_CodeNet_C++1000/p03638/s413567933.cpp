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
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int h, w; cin >> h >> w;
    int n; cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];
    vint tmp;
    rep(i,n) {
        rep(j,a[i]) tmp.push_back(i+1);
    }
    vvint field(h,vint(w));
    rep(i,h)rep(j,w) {
        if (!(i&1)) field[i][j] = tmp[i*w+j];
        else field[i][w-j-1] = tmp[i*w+j];
    }
    rep(i,h) {
        rep(j,w) cout << field[i][j] << " ";
        cout << endl;
    }

}