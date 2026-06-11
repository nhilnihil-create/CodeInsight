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
    int n; cin >> n;
    int ct_4 = 0; 
    int ct_2 = 0;
    rep(i,n) {
        int a; cin >> a;
        if (a % 4 == 0) ct_4++;
        else if (a % 2 == 0) ct_2++;
    }
    if (ct_2 != 0) n -= ct_2-1;
    if ((2*ct_4 + 1) >= n) cout << "Yes" << endl;
    else cout << "No" << endl;
}