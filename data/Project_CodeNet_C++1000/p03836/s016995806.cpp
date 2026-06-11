#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;


int main()
{
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    int dx = tx-sx;
    int dy = ty-sy;

    string ans = "";
    // 行き
    rep(i,dx)
    {
        ans += "R";
    }
    rep(i,dy)
    {
        ans += "U";
    }
    rep(i, dx)
    {
        ans += "L";
    }
    rep(i, dy)
    {
        ans += "D";
    }
    ans += "D";
    rep(i, dx+1)
    {
        ans += "R";
    }
    rep(i, dy+1)
    {
        ans += "U";
    }
    ans += "L";
    ans += "U";
    rep(i, dx + 1)
    {
        ans += "L";
    }
    rep(i, dy + 1)
    {
        ans += "D";
    }
    ans += "R";
    cout << ans << endl;
}