#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

int m[101][101][210];

bool f(int x, int y, int k){
    if(m[x][y][k] != -1) return m[x][y][k];
    if(x <= 1 && y <= 1){
        // cout << x << " " << y << " " << k << " " << 0 << endl;
        return m[x][y][k] = false;
    }
    bool res = true;
    rep(i, 1, x / 2 + 1){
        res &= f(x - 2 * i, y + i, k + 1);
    }
    rep(i, 1, y / 2 + 1){
        res &= f(x + i, y - 2 * i, k + 1);
    }
    // cout << x << " " << y << " " << k << " " << res << " " << !res << endl;
    return m[x][y][k] = !res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    // memset(m, -1, sizeof(m));
    // // cout << f(x, y, 0) << endl;
    // rep(i, 0, x + 1){
    //     rep(j, 0, y + 1){
    //         cout << f(i, j, 0) << " ";
    //     }
    //     cout << endl;
    // }
    if(abs(x - y) <= 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
}