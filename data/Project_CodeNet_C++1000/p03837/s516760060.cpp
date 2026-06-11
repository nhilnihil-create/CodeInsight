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
#define INF 200000000
#define mod 1000000007
#define INF2 1000000000000000000

int d[110][110];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, N) rep(j, N) d[i][j] = INF;
    rep(i, N) d[i][i] = 0;
    int a[100010], b[100010], c[100010];
    rep(i, M) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, M) {
        if(d[a[i]][b[i]] != c[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}
