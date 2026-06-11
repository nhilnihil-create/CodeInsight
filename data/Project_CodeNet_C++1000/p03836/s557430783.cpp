#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    REP(i, tx - sx) cout << "R";
    REP(i, ty - sy) cout << "U";
    REP(i, tx - sx) cout << "L";
    REP(i, ty - sy) cout << "D";
    cout << "D";
    REP(i, tx - sx + 1) cout << "R";
    REP(i, ty - sy + 1) cout << "U";
    cout << "LU";
    REP(i, tx - sx + 1) cout << "L";
    REP(i, ty - sy + 1) cout << "D";
    cout << "R" << endl;
    return 0;
}