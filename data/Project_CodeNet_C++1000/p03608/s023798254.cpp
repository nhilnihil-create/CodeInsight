#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Node {
  vector<int> edge_to;
  vector<int> edge_from;
  vector<ll> edge_cost;
  vector<ll> edge_from_cost;

  bool done;
  bool contain;
  ll cost;
};

int main() {
  int n, m, R;
  cin >> n >> m >> R;
  vector<int> r(R);
  for(int i = 0; i < R; i++) {
    cin >> r[i];
    r[i]--;
  }
  sort(r.begin(), r.end());
  vector<Node> node(n);
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    node[a].edge_to.push_back(b);
    node[a].edge_cost.push_back(c);
    node[b].edge_to.push_back(a);
    node[b].edge_cost.push_back(c);
  }

  vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, -1));
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < n; j++) {
      node[j].done = false;
      node[j].cost = -1;
    }
    auto compare = [](Node *a, Node *b) { return a->cost < b->cost; };
    priority_queue<Node, vector<Node*>, decltype(compare)> q{compare};
    node[r[i]].cost = 0;
    q.push(&node[r[i]]);
    while(!q.empty()) {
      Node doneNode = *q.top();
      q.pop();
      doneNode.done = true;
      for(int j = 0; j < doneNode.edge_to.size(); j++) {
        ll to = doneNode.edge_to[j];
        ll cost = doneNode.cost + doneNode.edge_cost[j];
        if(node[to].cost < 0 || cost < node[to].cost) {
          node[to].cost = cost;
          if(node[to].contain == false){
            q.push(&node[to]);
          }
        }
      }
    }
    for(int j = 0; j < R; j++) {
      dis[r[i]][r[j]] = node[r[j]].cost;
    }
  }

  ll ans = 100101001001001;
  do {
    ll sum = 0;
    for(int i = 0; i < R - 1; i++) {
      sum += dis[r[i]][r[i + 1]];
    }
    ans = min(ans, sum);
  } while(next_permutation(r.begin(), r.end()));

  cout << ans << endl;
  return 0;
}