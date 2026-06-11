#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>

#define MAX_K (100000)
#define MAX_L (100000)

using namespace std;

int dfs(const vector<vector<int>> &adj_lists, vector<int> &con_list,
        vector<int> &visited, int v, int g) {
  int ret = 1;
  for (int u : adj_lists[v]) {
    if (visited[u] < 0) {
      visited[u] = g;
      con_list.push_back(u);
      ret += dfs(adj_lists, con_list, visited, u, g);
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  // read inputs
  int N, K, L, ps[MAX_K], qs[MAX_K], rs[MAX_L], ss[MAX_L];
  scanf("%d %d %d", &N, &K, &L);
  for (int i = 0; i < K; i++) {
    scanf("%d %d", &ps[i], &qs[i]);
    ps[i]--;  // NOTE : modified input
    qs[i]--;  // NOTE : modified input
  }
  for (int i = 0; i < L; i++) {
    scanf("%d %d", &rs[i], &ss[i]);
    rs[i]--;  // NOTE : modified input
    ss[i]--;  // NOTE : modified input
  }

  // create graphs
  vector<vector<int>> adj_lists_road, adj_lists_rail;
  for (int i = 0; i < N; i++) {
    adj_lists_road.push_back(vector<int>());
    adj_lists_rail.push_back(vector<int>());
  }
  for (int i = 0; i < K; i++) {
    const int p = ps[i], q = qs[i];
    adj_lists_road[p].push_back(q);
    adj_lists_road[q].push_back(p);
  }
  for (int i = 0; i < L; i++) {
    const int r = rs[i], s = ss[i];
    adj_lists_rail[r].push_back(s);
    adj_lists_rail[s].push_back(r);
  }

  // create list of connected nodes
  int num_visited_road = 0, num_visited_rail = 0;
  vector<int> visited_road(N, -1), visited_rail(N, -1);
  vector<vector<int>> con_lists_road, con_lists_rail;
  for (int i = 0; i < N; i++) {
    if (visited_road[i] < 0) {
      const int num_groups = con_lists_road.size();
      visited_road[i] = num_groups;
      con_lists_road.push_back(vector<int>());
      vector<int> &con_list = con_lists_road[num_groups];
      con_list.push_back(i);
      num_visited_road +=
          dfs(adj_lists_road, con_list, visited_road, i, num_groups);
      if (num_visited_road == N) {
        break;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (visited_rail[i] < 0) {
      const int num_groups = con_lists_rail.size();
      visited_rail[i] = num_groups;
      con_lists_rail.push_back(vector<int>());
      vector<int> &con_list = con_lists_rail[num_groups];
      con_list.push_back(i);
      num_visited_rail +=
          dfs(adj_lists_rail, con_list, visited_rail, i, num_groups);
      if (num_visited_rail == N) {
        break;
      }
    }
  }

  for (vector<int> &con_list : con_lists_road) {
    sort(con_list.begin(), con_list.end());
  }
  for (vector<int> &con_list : con_lists_rail) {
    sort(con_list.begin(), con_list.end());
  }

  // count for each node
  vector<int> ans(N, -1);
  // for (int i = 0; i < N; i++) {
  //   if (ans[i] < 0) {
  //     int cnt = 0;
  //     for (int j : con_lists_road[visited_road[i]]) {
  //       if (visited_rail[i] == visited_rail[j]) {
  //         cnt++;
  //       }
  //     }
  //     for (int j : con_lists_road[visited_road[i]]) {
  //       if (visited_rail[i] == visited_rail[j]) {
  //         ans[j] = cnt;
  //       }
  //     }
  //   }
  // }
  for (vector<int> &con_list_road : con_lists_road) {
    map<int, int> num_groups;
    for (int i : con_list_road) {
      num_groups[visited_rail[i]] += 1;
    }
    for (int i : con_list_road) {
      ans[i] = num_groups[visited_rail[i]];
    }
  }

  for (int a : ans) {
    printf("%d ", a);
  }
  printf("\n");

  return 0;
}
