#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <tuple>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))
#define P(x, y) make_pair(x, y)

const int INF = 1000000009;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);


const int MAX = 300; /// 最大頂点数

ll N, ans; /// N:頂点数、M:辺の数

int dist[MAX][MAX]; /// dist[j][i]=dist[i][j]はi、j間の最短距離

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

bool warshall_floyd() {
  REP (k, N) REP (j, N) REP (i, N) if (dist[j][i] > dist[j][k] + dist[k][i]) return false;
  return true;
}

void warshall_floyd2() {
  REP (k, N) REP (j, N) FOR (i, j+1, N) if (k != j && k != i && dist[j][i] == dist[j][k] + dist[k][i]) {
    dist[j][i] = dist[i][j] = INF;
  }
}

int main() {
  cin >> N;
  Fill(dist, INF);


  REP (i, N) REP (j, N) {
    cin >> dist[i][j];
  }

  if (!warshall_floyd()) {
    cout << -1 << endl;
    return 0;
  }

  warshall_floyd2();
  ans = 0;
  REP (i, N) FOR (j, i+1, N) if (dist[j][i] != INF) {
    ans += dist[j][i];
  }

  cout << ans << endl;
  return 0;
}
