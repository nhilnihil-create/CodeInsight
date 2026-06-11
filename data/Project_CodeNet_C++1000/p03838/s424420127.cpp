#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    ll x,y;
    cin >> x >> y;
    ll ans;
    if(x >= 0) {
        if(y > 0) {
            if(y >= x) ans = y - x;
            else ans = y + x;
        } else {
            if(y >= -x) ans = y+x+1;
            else ans += -y-x+1; 
        }
    } else {
        if(y > 0) {
            if(y >= -x) ans = y+x+1;
            else ans = -y-x+1;
        } else {
            if(y >= x) ans = -x+y;
            else ans = 1 + -y+x + 1;
        }
    }
    cout << ans << endl;
}