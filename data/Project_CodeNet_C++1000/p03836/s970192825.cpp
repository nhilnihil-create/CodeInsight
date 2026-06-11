#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;

    string ans = string(dx, 'R') + string(dy, 'U') + string(dx, 'L') + string(dy, 'D')
                + string(1, 'D') + string(dx + 1, 'R') + string(dy + 1, 'U') + string(1, 'L')
                + string(1, 'U') + string(dx + 1, 'L') + string(dy + 1, 'D') + string(1, 'R');

    cout << ans << '\n';
}
