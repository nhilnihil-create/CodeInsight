#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int N, K, A[5001];
bool g[5001][5001], h[5001][5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    cin >> N >> K;
    rep(i, N)cin >> A[i];
    g[0][0] = h[N][0] = 1;
    rep(i, N)rep(j, K)if (g[i][j]) {
        if (j + A[i] < K)g[i + 1][j + A[i]] = 1;
        g[i + 1][j] = 1;
    }
    for (int i = N; i >= 1; --i)rep(j, K)if (h[i][j]) {
        if (j + A[i - 1] < K)h[i - 1][j + A[i - 1]] = 1;
        h[i - 1][j] = 1;
    }

    int ans = 0;
    rep(i, N)if (A[i] < K) {
        int y = K - 1;
        ans++;
        rep(x, K)if (g[i][x]) {
            while (y >= 0 && (!h[i + 1][y] || x + y >= K))y--;
            if (y >= 0 && x + y >= K - A[i]) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}