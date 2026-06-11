#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print(const vector<int> &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

template<typename T>
struct toedge {
  int to;
  T cost;

  toedge(int to) : to(to), cost((T)1) {}

  toedge(int to, T cost) : to(to), cost(cost) {}
};

template<typename T>
using ToEdges = vector<vector<toedge<T>>>;

template<typename T>
void dijkstra(std::vector<T> &distance, const ToEdges<T> &edges, const int s) {

  using P = std::pair<T, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;

  distance[s] = 0;
  que.emplace(distance[s], s);
  while(!que.empty()) {
    P p = que.top();
    que.pop();
    T cost = p.first;
    int v = p.second;
    if(distance[v] < cost) continue;
    for(auto &e : edges[v]) {
      if(distance[e.to] > distance[v] + e.cost) {
        distance[e.to] = distance[v] + e.cost;
        que.emplace(distance[e.to], e.to);
      }
    }
  }
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  ToEdges<int> edges(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    edges[a].emplace_back(b);
    edges[b].emplace_back(a);
  }
  VI dist1(n, INF), distn(n, INF);
  dijkstra<int>(dist1, edges, 0);
  dijkstra<int>(distn, edges, n-1);
  int c1, cn;
  c1 = cn = 0;
  rep(i, n) {
    dist1[i] > distn[i] ? cn++ : c1++;
  }
  c1 > cn ? out("Fennec") : out("Snuke");
  return 0;
}
