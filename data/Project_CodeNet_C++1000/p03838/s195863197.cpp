#include <bits/stdc++.h>
#define repl(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll positive(ll x){
    if(x < 0)return -x;
    else return x;
}
//ミョ(-ω- ?)
int main() {
    ll x,y;
    cin >> x >> y;
    ll res = LONG_LONG_MAX;
    if (x <= y)  chmin(res, y - x);
    if (-x <= y) chmin(res, y + x + 1);
    if (x <= -y) chmin(res, -y - x + 1);
    if (-x <= -y)chmin(res, -y + x + 2);
    cout << res << endl;
    return 0;
}