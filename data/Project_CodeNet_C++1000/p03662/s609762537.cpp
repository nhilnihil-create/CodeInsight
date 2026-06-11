#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <vector>

#define MAX_N (100000)

using namespace std;

void bfs(const vector<vector<int>> &adj_lists, int s, vector<int> &distances) {
  queue<int> que;
  que.push(s);
  distances[s] = 0;
  while (!que.empty()) {
    const int v = que.front();
    que.pop();
    for (int u : adj_lists[v]) {
      if (distances[u] < 0) {
        que.push(u);
        distances[u] = distances[v] + 1;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  // read inputs
  int N, as[MAX_N - 1], bs[MAX_N - 1];
  scanf("%d", &N);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &as[i], &bs[i]);
    as[i]--;  // NOTE modified input
    bs[i]--;  // NOTE modified input
  }

  // create graph
  vector<vector<int>> adj_lists;
  // add nodes
  for (int i = 0; i < N; i++) {
    adj_lists.push_back(vector<int>());
  }
  // add edges
  for (int i = 0; i < N - 1; i++) {
    const int a = as[i], b = bs[i];
    adj_lists[a].push_back(b);
    adj_lists[b].push_back(a);
  }

  // calculate distances
  vector<int> d_from_fs(N, -1), d_from_ss(N, -1);
  bfs(adj_lists, 0, d_from_fs);
  bfs(adj_lists, N - 1, d_from_ss);

  // solve
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que_f, que_s;
  vector<int> used(N, 0);
  que_f.push(pair<int, int>(d_from_ss[0], 0));
  que_s.push(pair<int, int>(d_from_fs[N - 1], N - 1));
  while (1) {
    // fennec's turn
    // choose square closest to snuke not yet taken
    int node_taken_f = -1;
    while (!que_f.empty()) {
      const pair<int, int> p = que_f.top();
      const int d = p.first, v = p.second;
      que_f.pop();
      if (!used[v]) {
        used[v] = 1;
        node_taken_f = v;
        for (int u : adj_lists[v]) {
          que_f.push(pair<int, int>(d_from_ss[u], u));
        }
        // printf("Fennec took %d\n", v);
        break;
      }
    }
    if (node_taken_f < 0) {
      printf("Snuke\n");
      break;
    }

    // snuke's turn
    // choose square closest to fennec not yet taken
    int node_taken_s = -1;
    while (!que_s.empty()) {
      const pair<int, int> p = que_s.top();
      const int d = p.first, v = p.second;
      que_s.pop();
      if (!used[v]) {
        used[v] = 1;
        node_taken_s = v;
        for (int u : adj_lists[v]) {
          que_s.push(pair<int, int>(d_from_fs[u], u));
        }
        // printf("Snuke took %d\n", v);
        break;
      }
    }
    if (node_taken_s < 0) {
      printf("Fennec\n");
      break;
    }
  }

  return 0;
}
