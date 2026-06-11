#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
map<P, ll> dis{};
int N;
vector<vector<int>> tunagari(0, vector<int>(0, 0));
vector<ll> Ans(0);
void dfs(int sectionid, int beforeid) {
  for (int i = 0; i<tunagari[sectionid].size(); i++) {
    int a = tunagari[sectionid][i];
    int sec = sectionid;
    if (a == beforeid) continue;
    Ans[a] = Ans[sectionid] + dis[P(sectionid, a)];
    dfs(a, sectionid);
  }
}
int main() {
  cin >> N;
  tunagari.resize(N);
  Ans.resize(N);
  REP(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    dis[P(a, b)] = c;
    dis[P(b, a)] = c;
    tunagari[a].push_back(b);
    tunagari[b].push_back(a);
  }
  int Q, K;
  cin >> Q >> K, K--;
  Ans[K] = 0;
  dfs(K, -1);
  REP(i, Q) { int x, y;
    cin >> x >> y,x--,y--;
    cout << Ans[x] + Ans[y] << endl;
  }
}