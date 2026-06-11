#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) {rep(a,x.size()) cout << x[a] << " "; cout << endl;}
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
const ll inf_l = 1e18;
const int MAX = 2e5;

int main() {
    int n, a, b; cin >> n >> a >> b;
    if (b < a) cout << 0 << endl; 
    else if (n == 1) {
        if (a != b) cout << 0 << endl;
        else cout << 1 << endl;
    } 
    else if (n == 2) {
        if (a == b) cout << 0 << endl;
        else cout << 1 << endl;
    }
    else {
        cout << (ll)(b-a)*(n-2)+1 << endl;;
    }
}