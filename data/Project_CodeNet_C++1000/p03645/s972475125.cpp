#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

struct Graph {
    struct Edge { int from; int to; lint cost; };
    struct Node {
        Node() : par(-1), done(false), dist(INF) {}
        int index;
        int par;
        bool done;
        lint dist;
        vector<Edge> edge;
    };

    int n;
    vector<Node> nodes;
    vector<Edge> edges;
    const static lint INF = 1e18;

    Graph(int n) : n(n) {
        nodes.resize(n);
        for(int i=0; i<n; i++)  nodes[i].index = i;
    }

    void add_edge(int from, int to, lint cost) {
        nodes[from].edge.push_back(Edge{from, to, cost});
        edges.push_back(Edge{from, to, cost});
    }

    void bfs(int s) {
        queue<int> que;
        nodes[s].dist = 0;
        que.push(s);

        while(!que.empty()) {
            int index = que.front(); que.pop();
            for(auto& e : nodes[index].edge) {
                if(nodes[e.to].dist != INF)  continue;
                nodes[e.to].dist = nodes[index].dist + 1;
                nodes[e.to].par = index;
                que.push(e.to);
            }
        }
    }

    lint shortest_dist(int to) { return nodes[to].dist; }
};

int main() {
  lint N, M;
  cin >> N >> M;

  Graph g(N);
  for(lint i=0; i<M; i++) {
    lint a, b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a, b, 1);
    g.add_edge(b, a, 1);
  }

  g.bfs(0);
  cout << (g.shortest_dist(N-1) == 2 ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}