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

int main() {
    int n, m; cin >> n >> m;
    vector<queue<int>> data(n);
    rep(i,n) {
        rep(j,m) {
            int x; cin >> x;
            data[i].push(x);
        }
    }
    set<int> use;
    REP(i,m+1) use.insert(i);
    int ans = inf;
    while (use.size() != 0) {
        map<int,int> ct;
        rep(i,n) {
            while (true) {
                int x = data[i].front();
                if (!use.count(x)) data[i].pop();
                else {
                    ct[x]++;
                    break;
                }
            }
        }
        int mx = 0;
        int omit;
        for (P p : ct) {
            if (chmax(mx,p.second)) omit = p.first;
        }
        ans = min(ans,mx);
        use.erase(omit);
    }
    cout << ans << endl;
}