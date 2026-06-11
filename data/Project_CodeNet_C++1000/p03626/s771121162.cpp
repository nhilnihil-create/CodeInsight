#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
constexpr long long int INF = std::numeric_limits<long long int>::max();
constexpr long long int NINF = std::numeric_limits<long long int>::min();
constexpr long long int MOD = 1000000007;
#define int long long int

enum {
  SINGLE = 0,
  DOUBLE = 1,
};

vector<int> dist(100001, -1);
vector<vector<pair<int, int>>> E(100001);

void dfs(int pos) {
  for (pair<int, int> &p : E[pos]) {
    if (dist[p.first] >= 0) {
      continue;
    }

    dist[p.first] = dist[pos] + p.second;
    dfs(p.first);
  }
}

void solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans, i, prev;
  if (S[0] == S[1]) {
    ans = 6;
    i = 2;
    prev = DOUBLE;
  } else {
    ans = 3;
    i = 1;
    prev = SINGLE;
  }

  while (i < S.size()) {
    if (i + 1 == S.size() || S[i] != S[i + 1]) {
      if (prev == SINGLE) {
        ans = (ans * 2) % MOD;
      } else {
        // ans = ans * 1
      }

      prev = SINGLE;
      i++;
    } else {
      if (prev == SINGLE) {
        ans = (ans * 2) % MOD;
      } else {
        ans = (ans * 3) % MOD;
      }
      prev = DOUBLE;
      i += 2;
    }
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
