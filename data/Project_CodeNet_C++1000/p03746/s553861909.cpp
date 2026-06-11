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

int N, M;
vector<int> G[100000];
vector<int> vc;
vector<int> ans;
vector<bool> visit(100000, false);

void dfs(int p) {
  visit[p] = true;
  REP(i, G[p].size()) {
    int q = G[p][i];
    if (!visit[q]) {
      vc.push_back(q);
      dfs(q);
      break;
    }
  }
}

int main() {
  cin >> N >> M;
  REP(i, M) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  dfs(0);
  reverse(ALL(vc));
  REP(i, vc.size()) ans.push_back(vc[i]);
  ans.push_back(0);
  vc.clear();
  dfs(0);
  REP(i, vc.size()) ans.push_back(vc[i]);
  cout << ans.size() << endl;
  REP(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << "\n";
  return 0;
}