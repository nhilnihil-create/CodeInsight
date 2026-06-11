#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
int d[110][110];
int u[1010], v[1010], r[1010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    rep(i, 110) rep(j, 110) d[i][j] = INF/10;
    rep(i, 110) d[i][i] = 0;
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = d[b][a] = c;
        u[i] = a, v[i] = b, r[i] = c;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, m) {
        if(d[u[i]][v[i]] != r[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}
