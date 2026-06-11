#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint INF = 1e15;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
struct Node;
vector<Node> V;
struct Node {
  lint dist = INF;
  vector<int> nbr;
  vector<lint> cost;
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  REP(i, N) V.emplace_back();
  REP(i, M) {
    int a, b; lint c;
    cin >> a >> b >> c;
    a--; b--;
    V[a].nbr.push_back(b);
    V[a].cost.push_back(-c);
  }
  V[0].dist = 0;
  REP(k, N*2) REP(i, N) REP(j, V[i].nbr.size()) {
    if(k >= N && V[i].dist + V[i].cost[j] < V[V[i].nbr[j]].dist) {
      V[V[i].nbr[j]].dist = -INF;
    } else if(V[i].dist + V[i].cost[j] < V[V[i].nbr[j]].dist) {
      V[V[i].nbr[j]].dist = V[i].dist + V[i].cost[j];
    }
  }
  if(V[N-1].dist == -INF) cout << "inf" << endl;
  else cout << -V[N-1].dist << endl;
}