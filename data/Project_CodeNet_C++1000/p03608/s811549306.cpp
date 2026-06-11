#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int n, m, r;
vector<int> R;

void solve(std::vector<std::vector<int>> w_s, const int num_vertices) {
  std::vector<std::vector<ll>> dist(num_vertices);
  for (auto& dim : dist) {
    for (auto i = 0; i < num_vertices; ++i) {
      dim.push_back(INF);
    }
  }
  for (auto& w : w_s) {
    dist[w[0]][w[1]] = w[2];
  }
  std::vector<std::vector<int>> next(num_vertices);
  for (auto i = 0; i < num_vertices; ++i) {
    for (auto j = 0; j < num_vertices; ++j) {
      next[i].push_back(0);
    }
    for (auto j = 0; j < num_vertices; ++j) {
      if (i != j) {
        next[i][j] = j + 1;
      }
    }
  }
  for (auto k = 0; k < num_vertices; ++k) {
    for (auto i = 0; i < num_vertices; ++i) {
      for (auto j = 0; j < num_vertices; ++j) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  sort(R.begin(), R.end());
  ll ans=INFll;
  do {
    ll cand=0;
    rep(i, r-1){
      cand+=dist[R[i]][R[i+1]];
    }
    if(ans>cand){
      ans=cand;
    }
  } while (std::next_permutation(R.begin(), R.end()));
  cout << ans << endl;
}


int main() {
  cin >> n >> m >> r;
  R.resize(r);
  rep(i, r){
    cin >> R[i];
    --R[i];
  }
  std::vector<std::vector<int>> w(m*2, vector<int>(3));
  int a, b, c;
  rep(i, m){
    cin >> a >> b >> c;
    --a; --b;
    w[i][0]=a; w[i][1]=b; w[i][2]=c;
    w[i+m][0]=b; w[i+m][1]=a; w[i+m][2]=c;
  }
  solve(w, n);
  return 0;
}
/*
Output:
(pair, dist, path)
(1 -> 2, -1, 1 -> 3 -> 4 -> 2)
(1 -> 3, -2, 1 -> 3)
(1 -> 4, 0, 1 -> 3 -> 4)
(2 -> 1, 4, 2 -> 1)
(2 -> 3, 2, 2 -> 1 -> 3)
(2 -> 4, 4, 2 -> 1 -> 3 -> 4)
(3 -> 1, 5, 3 -> 4 -> 2 -> 1)
(3 -> 2, 1, 3 -> 4 -> 2)
(3 -> 4, 2, 3 -> 4)
(4 -> 1, 3, 4 -> 2 -> 1)
(4 -> 2, -1, 4 -> 2)
(4 -> 3, 1, 4 -> 2 -> 1 -> 3)
*/
