#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) {rep(i,x.size()) cout << x[i] << " "; cout << endl;}
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9+7;
const ll inf_l = 1e18;
const int MAX = 1e7+10;

int main() {
    int n; cin >> n;
    set<int> od;
    vint a(n);
    rep(i,n) {
        int x; cin >> x;
        if (i&1) od.insert(x);
        a[i] = x;
    }
    sort(all(a));
    int ans = 0;
    rep(i,n) {
        if (i&1 && !od.count(a[i])) ans++;
    }
    cout << ans << endl;
}