#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll x, y; cin >> x >> y;
    ll x_ = abs(x), y_ = abs(y);
    ll res;
    if(x == -y) res = 1;
    else if(x > y){
        if(x>0 && y>0) res = x-y+2;
        if(x>0 && y<0) res = abs(x_-y_)+1;
        if(x<0 && y<0) res = abs(x_-y_)+2;
        if(x == 0 || y == 0) res = abs(x-y)+1;
    }else{
        if(x>0 && y>0) res = y-x;
        if(x<0 && y>0) res = abs(abs(y)- abs(x))+1;
        if(x<0 && y<0) res = abs(x-y);
        if(x== 0 || y==0) res = abs(x-y);
    }
    cout << res << ln;
}
