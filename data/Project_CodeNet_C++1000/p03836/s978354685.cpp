#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    ll dx=tx-sx,dy=ty-sy;
    string ans;
    rep(i,dy) ans.push_back('U');
    rep(i,dx) ans.push_back('R');
    rep(i,dy) ans.push_back('D');
    rep(i,dx) ans.push_back('L');
    ans.push_back('L');
    rep(i,dy+1) ans.push_back('U');
    rep(i,dx+1) ans.push_back('R');
    ans.push_back('D');
    ans.push_back('R');
    rep(i,dy+1) ans.push_back('D');
    rep(i,dx+1) ans.push_back('L');
    ans.push_back('U');

    cout << ans << endl;
}
    