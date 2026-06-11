#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using pll = pair<ll,ll>;
const ll INF64 = 1LL << 60;
const int INF = (1 << 29);

int main(){
    int sx,sy,tx,ty; cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    string ans;
    rep(i,dx) ans.push_back('R');
    rep(i,dy) ans.push_back('U');
    rep(i,dx) ans.push_back('L');
    rep(i,dy) ans.push_back('D');
    ans.push_back('D');
    rep(i,dx+1) ans.push_back('R');
    rep(i,dy+1) ans.push_back('U');
    ans.push_back('L');
    ans.push_back('U');
    rep(i,dx+1) ans.push_back('L');
    rep(i,dy+1) ans.push_back('D');
    ans.push_back('R');

    cout << ans << endl;
}