#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int n;
vector<int> g[100000];

int dfs(int x) {
  vector<int> vc;
  int k = g[x].size();
  REP(i, k) vc.push_back(dfs(g[x][i]));
  sort(ALL(vc));
  int res = 0;
  REP(i, k) res = max(res, vc[i] + k - i);
  return res;
}

int main() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a;
    cin >> a;
    a--;
    g[a].push_back(i);
  }
  cout << dfs(0) << endl;
  return 0;
}