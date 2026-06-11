#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x, y;
    cin >> x >> y;
    ll mx = -x, my = -y;
    ll ans = 1e18;
    if(x < y) chmin(ans, y - x);
    if(mx <= y) chmin(ans, y - mx + 1);
    if(x <= my) chmin(ans, my - x + 1);
    if(mx <= my) chmin(ans, my - mx + 2);
    cout << ans << endl;
    return 0;
}