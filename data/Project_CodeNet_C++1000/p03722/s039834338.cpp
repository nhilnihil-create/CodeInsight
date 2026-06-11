#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

template<typename T> struct WG{
  using P = tuple<int, int, T>;
  int n; T inf = 2000000000000000000;
  vector<bool> negative_loop;
  vector<P> edges;
  vector<T> ans;
  WG(int n_){
    n = n_;
    ans.resize(n, inf);
    negative_loop.resize(n, false);
  }
  void add_edge(int from, int to, T cost){
    P edge = make_tuple(from, to, cost);
    edges.push_back(edge);
  }
  void bellmanford(int start){
    ans[start] = 0;
    for(int i = 0; i < n*2; ++i){
      for(int j = 0; j < edges.size(); ++j){
        int from = get<0>(edges[j]);
        int to = get<1>(edges[j]);
        T cost = get<2>(edges[j]);
        if(ans[from] < inf && ans[to] > ans[from] + cost){
          ans[to] = ans[from] + cost;
          if(i > n-2) negative_loop[to] = true;
        }
        if(negative_loop[from]) negative_loop[to] = true;
      }
    }
  }
};

int main(){
  int n, m; cin >> n >> m;
  WG<long> g(n);
  rep(i, m){
    int a, b; long c; cin >> a >> b >> c; --a; --b;
    g.add_edge(a, b, -1*c);
  }
  g.bellmanford(0);
  if(g.negative_loop[n-1]) cout << "inf\n";
  else cout << g.ans[n-1] * -1<< "\n";
  return 0;
}
