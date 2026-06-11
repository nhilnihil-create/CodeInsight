#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

struct Edge {
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int main(){
  int N;
  cin >> N;
  vector<int> a(N - 1), b(N - 1);
  REP(i,N - 1) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }

  Graph g(N);
  REP(i,N - 1) {
    g[a[i]].push_back(Edge(a[i], b[i]));
    g[b[i]].push_back(Edge(b[i], a[i]));
  }

  vector<int> prev(N, -2);
  queue<Edge> que;
  que.push(Edge(-1, 0));
  while(!que.empty()) {
    Edge q = que.front();
    que.pop();
    prev[q.dst] = q.src;
    for(Edge e: g[q.dst]) {
      if(prev[e.dst] != -2) continue;
      que.push(e);
    }
  }

  vector<int> path;
  int pos = N - 1;
  while(pos != -1) {
    path.push_back(pos);
    pos = prev[pos];
  }

  vector<int> c(N, 0);
  REP(i, path.size()) {
    if(i < path.size() / 2) c[path[i]] = -1;
    else c[path[i]] = 1;
  }

  queue<int> que2;
  REP(i, N) if(c[i] != 0) que2.push(i);
  while(!que2.empty()) {
    int q = que2.front();
    que2.pop();
    for(Edge e: g[q]) {
      if(c[e.dst] != 0) continue;
      c[e.dst] = c[e.src];
      que2.push(e.dst);
    }
  }

  int sum = 0;
  REP(i,N) sum += c[i];
  string ret = (sum > 0) ? "Fennec" : "Snuke";
  cout << ret << endl;

  return 0;
}

