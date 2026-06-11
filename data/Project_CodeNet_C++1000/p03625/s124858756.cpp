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
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1LL<<62;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    map<int,int> ct;
    rep(i,n) {
        int x; cin >> x;
        ct[x]++;
    }
    vint x;
    for (auto itr = ct.begin(); itr != ct.end(); itr++) {
        if (itr->second >= 2) x.push_back(itr->first);
    }
    sort(rall(x));
    if (x.size() == 0) cout << 0 << endl;
    else if (x.size() == 1) {
        if (ct[x[0]] >= 4) cout << (ll)x[0]*x[0] << endl;
        else cout << 0 << endl;
    }
    else if (x.size() >= 2) {
        if (ct[x[0]] >= 4) cout << (ll)x[0]*x[0] << endl;
        else cout << (ll)x[0]*x[1] << endl;
    }
}