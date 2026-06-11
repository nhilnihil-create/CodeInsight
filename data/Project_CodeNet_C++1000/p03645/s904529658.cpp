#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long H, W;
vector<vector<long long>> cost_map(1000+1, vector<long long>(1000+1, 0));

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> island_map(N);
  for(int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    island_map[a-1].push_back(b-1);
    island_map[b-1].push_back(a-1);
  }

  for(int u : island_map[0]) {
    for(int v : island_map[u]) {
      if(v == N-1) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
