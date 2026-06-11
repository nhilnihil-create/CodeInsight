#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int dist[105][105];
int A[1005], B[1005], C[1005];
int ans;

int main(void) {
  int n, m;
  cin >> n >> m;
  rep(i, 0, 105) rep(j, 0, 105) {
    if (i==j) dist[i][j] = 0;
    else dist[i][j] = INF;
  }
  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = dist[b][a] = c;
    A[i] = a;
    B[i] = b;
    C[i] = c;
  }

  for (int k=0; k<n; k++) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }

  for (int k=0; k<m; k++) {
    bool flag = false;
    int a = A[k], b = B[k], c = C[k];
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (dist[i][j]==dist[i][a]+dist[b][j]+c) flag = true;
      }
    }
    if (!flag) ans++;
  }
  

  
  cout << ans << endl;

    return 0;
}

