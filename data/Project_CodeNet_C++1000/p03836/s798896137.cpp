#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    string ans = "";
    rep(i, dy) ans += 'U';
    rep(i, dx) ans += 'R';
    rep(i, dy) ans += 'D';
    rep(i, dx) ans += 'L';
    ans += 'L';
    rep(i, dy+1) ans += 'U';
    rep(i, dx+1) ans += 'R';
    ans += 'D';
    ans += 'R';
    rep(i, dy+1) ans += 'D';
    rep(i, dx+1) ans += 'L';
    ans += 'U';
    cout << ans << endl; 
}