#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)
#define FOR(i, b, n) for (long i = b; i <= n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;
const string YES = "POSSIBLE";
const string NO = "IMPOSSIBLE";

void solve(long N, long M, vector<long> a, vector<long> b) {
  vector<int> score(N + 1, 0);

  REP(i, M) {
    
    if (a[i] == 1 || a[i] == N)
      score[b[i]]++;

    if (b[i] == 1 || b[i] == N)
      score[a[i]]++;
  }

  FOR(i, 1, N) {
    // cout << i << " " << score[i] << endl;
    if (score[i] > 1) {
      cout << YES << endl;
      return;
    }
  }
  cout << NO << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N, M;
  cin >> N >> M;
  vector<long> a(M);
  vector<long> b(M);
  REP(i, M)
    cin >> a[i] >> b[i];

  solve(N, M, move(a), move(b));
  return 0;
}
