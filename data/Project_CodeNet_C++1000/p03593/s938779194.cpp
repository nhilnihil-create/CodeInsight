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
    int h, w; cin >> h >> w;
    map<char,int> mp;
    rep(i,h)rep(j,w) {
        char x; cin >> x;
        mp[x]++;
    }
    bool ok = false;
    if (h&1 && w&1) {
        int ct_4 = 0;
        for (P p : mp) {
            ct_4 += p.second / 4;
            mp[p.first] = p.second % 4;
        }
        int ct_2 = 0;
        for (P p : mp) {
            ct_2 += p.second / 2;
            mp[p.first] = p.second % 2;
        }
        if (ct_4 >= (h/2) * (w/2)) {
            ct_2 += (ct_4 - ((h/2) * (w/2))) * 2;
            if (ct_2 == h/2 + w/2) ok = true;
        }
    } else if (!(h&1) && !(w&1)) {
        int ct_4 = 0;
        for (P p : mp) ct_4 += p.second / 4;
        if (ct_4 == (h/2) * (w/2)) ok = true;
    } else {
        int ct_4 = 0;
        for (P p : mp) {
            ct_4 += p.second / 4;
            mp[p.first] = p.second % 4;
        }
        int ct_2 = 0;
        for (P p : mp) ct_2 += p.second / 2;
        if (ct_4 >= (h/2) * (w/2)) {
            ct_2 += (ct_4 - (h/2) * (w/2)) * 2;
            if (w&1 && ct_2 == h/2) ok = true;
            if (h&1 && ct_2 == w/2) ok = true;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}