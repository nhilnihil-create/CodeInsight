#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {


    ll sx,sy,tx,ty; cin >> sx >> sy >> tx >> ty;
    ll dx = tx-sx,dy = ty-sy;
    string ans;

    //loop1
    rep(i,dy) ans += 'U';
    rep(i,dx) ans += 'R';
    rep(i,dy) ans += 'D';
    rep(i,dx) ans += 'L';

    //loop2
    ans += 'L';
    rep(i,dy+1) ans += 'U';
    rep(i,dx+1) ans += 'R';
    ans += 'D';
    ans += 'R';
    rep(i,dy+1) ans += 'D';
    rep(i,dx+1) ans += 'L';
    ans += 'U';

    cout << ans;


    return 0;
}
