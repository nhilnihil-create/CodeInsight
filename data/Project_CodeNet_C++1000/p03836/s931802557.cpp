#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 998244353;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int ddx = tx - sx;
    int ddy = ty - sy;
    string ans;
    rep(i, ddx) {
        ans += 'R';
    }
    rep(i, ddy) {
        ans += 'U';
    }
    ans += 'R';
    rep(i, ddy + 1) {
        ans += 'D';
    }
    rep(i, ddx + 1) {
        ans += 'L';
    }
    ans +='U';
    ans += 'L';
    rep(i, ddy + 1) {
        ans += 'U';
    }
    rep(i, ddx + 1) {
        ans += 'R';
    }
    ans += 'D';
    rep(i, ddx) {
        ans += 'L';
    }
    rep(i, ddy) {
        ans += 'D';
    }
    cout << ans << endl;
    return 0;
}