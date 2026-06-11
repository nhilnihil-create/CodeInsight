#include <iostream>
#include <vector>
#include <iomanip>
#define INF 1100000000
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int mp[220000][26];
int dp[220000];
int main()
{
  string S; cin >> S;
  S.insert(S.begin(), 'X'); S.push_back('X');

  vector<int> nextalf(26, S.size() - 1);
  REP(i, 26) mp[S.size() - 1][i] = S.size();
  for (int i = S.size() - 2; i >= 0; i--) {
    REP(j, 26) mp[i][j] = nextalf[j];
    nextalf[S[i] - 'a'] = i;
  }

  REP(i, 220000) dp[i] = INF;
  dp[0] = 0;
  REP(i, S.size()) {
    REP(j, 26) {
      dp[mp[i][j]] = min(dp[mp[i][j]], dp[i] + 1);
    }
  }

  vector<bool> in_shortest_path(S.size(), false);
  in_shortest_path.back() = true;
  for (int i = S.size() - 1; i >= 0; i--) {
    REP(j, 26) {
      if (dp[mp[i][j]] == dp[i] + 1 && in_shortest_path[mp[i][j]])
        in_shortest_path[i] = true;
    }
  }

  int now = 0;
  string ans = "";
  while (now < S.size() - 1) {
    REP(i, 26) {
      if (dp[mp[now][i]] == dp[now] + 1 && in_shortest_path[mp[now][i]]) {
        ans += i + 'a';
        now = mp[now][i];
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}