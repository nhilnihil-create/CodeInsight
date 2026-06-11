#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


int N; // 頂点数
const int MAX_N = 300;
const int INFC = 1000000000;
vector<vector<int>> d(MAX_N, vector<int>(MAX_N, INFC));
  // d[u][v]...辺e=(u,v)のコスト。存在しない場合はINF, 但しd[i][i]=0とする

void warshall_floyd() {
  rep(i, N) d[i][i] = 0;
  for (int k=0; k<N; k++) for (int i=0; i<N; i++) for (int j=0; j<N; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

vector<int> r;
int res = INFC;

int main() {
  int M; cin >>N >>M;
  int R; cin >>R;
  r.assign(R, 0);
  rep(i, R) cin >>r.at(i);
  rep(i, R) r.at(i)--;
  rep(i, M){
    int a,b,t; cin >>a >>b >>t; a--; b--;
    d[a][b] = t; d[b][a] = t;
  }
  warshall_floyd();
  vector<int> a(R); rep(i, R) a[i] = i;
  sort(all(a));
  do {
    int ans = 0;
    for (int i=0; i<R-1; i++){
      int v = r[a[i]], nv = r[a[i+1]];
      ans += d[v][nv];
    }
    res = min(res, ans);
  } while (next_permutation(all(a)));

  cout <<res <<endl;
}
