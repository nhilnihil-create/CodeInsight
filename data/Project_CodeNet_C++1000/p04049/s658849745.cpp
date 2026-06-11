#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T>
struct edge {
    int src, to;
    T cost;

    // to, costで初期化
    edge (int to, T cost) : src(-1), to(to), cost(cost) {}

    // src, to, costで初期化
    edge (int src, int to, T cost) : src(src), to(to), cost(cost) {}

    // toにxを代入？
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    
    // edge()でtoを返す？
    operator int() const {return to;}
};

// templates
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<Edges<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/*
 * Dijkstra
 * input: WeightedGraph<T> &g: グラフ
 *        int s: 始点
 * output: vector<T>: sから各要素への最短経路長
 */
template<typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(g.size(), INF);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while(!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  int n, k; cin >> n >> k;
  WeightedGraph<int> g(n);
  Edges<int> e;
  for(int i=0;i<n-1;++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(edge<int>(a, b, 1));
    g[b].push_back(edge<int>(b, a, 1));
    e.push_back(edge<int>(a, b, -1));
  }

  vector<vector<int>> dist(n);

  for(int i=0;i<n;++i) {
    dist[i] = dijkstra(g, i);
  }

  if(k % 2 == 0) {
    int mi = INF;
    for(int i=0;i<n;++i) {
      int cnt = 0;
      for(int j=0;j<n;++j) {
        if(dist[i][j] > k/2) {
          cnt++;
        }
      }
      mi = min(mi, cnt);
    }
    cout << mi << endl;
  } else {
    int sz = e.size();
    int mi = INF;
    for(int i=0;i<sz;++i) {
      int cnt = 0;
      int a = e[i].src;
      int b = e[i].to;
      for(int j=0;j<n;++j) {
        if(min(dist[a][j], dist[b][j]) > k/2) {
          cnt++;
        }
      }
      mi = min(mi, cnt);
    }
    cout << mi << endl;
  }


  
}
