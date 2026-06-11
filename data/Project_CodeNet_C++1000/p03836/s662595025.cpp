#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string ans;

    rep(i, 0, tx-sx)ans += 'R';
    rep(i, 0, ty-sy)ans += 'U';
    rep(i, 0, tx-sx)ans += 'L';
    rep(i, 0, ty-sy)ans += 'D';

    ans += 'D';
    rep(i, 0, tx-sx)ans += 'R';
    ans += 'R';
    rep(i, 0, ty-sy)ans += 'U';
    ans += 'U';
    ans += 'L';
    ans += 'U';
    rep(i, 0, tx-sx)ans += 'L';
    ans += 'L';
    rep(i, 0, ty-sy)ans += 'D';
    ans += 'D';
    ans += 'R';

    cout << ans << endl;
}