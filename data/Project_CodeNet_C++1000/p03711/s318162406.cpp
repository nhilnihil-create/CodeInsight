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
const int mod = 1e9+7;

int main() {
    int x, y; cin >> x >> y;
    set<int> a = {1,3,5,7,8,10,12};
    set<int> b = {4,6,9,11};
    set<int> c = {2};
    char x_group, y_group;
    if (a.find(x) != a.end()) x_group = 'a';
    if (b.find(x) != b.end()) x_group = 'b';
    if (c.find(x) != c.end()) x_group = 'c';
    if (a.find(y) != a.end()) y_group = 'a';
    if (b.find(y) != b.end()) y_group = 'b';
    if (c.find(y) != c.end()) y_group = 'c';
    if (x_group == y_group) cout << "Yes" << endl;
    else cout << "No" << endl;
}