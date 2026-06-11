#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int dx, dy;
    dx = tx - sx;
    dy = ty - sy;
    rep(i,dy) cout << "U";
    rep(i,dx) cout << "R";
    rep(i,dy) cout << "D";
    rep(i,dx+1) cout << "L";
    rep(i,dy+1) cout << "U";
    rep(i,dx+1) cout << "R";
    cout << "DR";
    rep(i,dy+1) cout << "D";
    rep(i,dx+1) cout << "L";
    cout << "U" << endl;
    return 0;
}
