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
const int inf = 1e9+7;
const ll inf_l = 1e18;
const int MAX = 1e6;

int main() {
    string x; cin >> x;
    stack<char> s;
    rep(i,x.size()) {
        if (x[i] == 'S') s.push(x[i]);
        else {
            if (s.size() != 0 && s.top() == 'S') s.pop();
            else s.push(x[i]);
        }
    }
    cout << s.size() << endl;
}