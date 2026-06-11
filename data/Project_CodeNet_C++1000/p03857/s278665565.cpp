#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <vector>

#define MAX_K (100000)
#define MAX_L (100000)

using namespace std;

void add_edge(vector<vector<int>> &adj_lists, int i, int j) {
  adj_lists[i].push_back(j);
  adj_lists[j].push_back(i);
}

void dfs(vector<vector<int>> &adj_lists, vector<int> &gs, int i, int g) {
  gs[i] = g;
  for (int j : adj_lists[i]) {
    if (gs[j] < 0) {
      dfs(adj_lists, gs, j, g);
    }
  }
}

int main() {
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
  vector<vector<int>> road_adj_lists(N, vector<int>()),
      railway_adj_lists(N, vector<int>());
  for (int i = 0; i < K; i++) {
    add_edge(road_adj_lists, ps[i], qs[i]);
  }
  for (int i = 0; i < L; i++) {
    add_edge(railway_adj_lists, rs[i], ss[i]);
  }

  // decompose
  vector<int> road_gs(N, -1), railway_gs(N, -1);
  int g = 0;
  for (int i = 0; i < N; i++) {
    if (road_gs[i] < 0) {
      dfs(road_adj_lists, road_gs, i, g++);
    }
  }
  g = 0;
  for (int i = 0; i < N; i++) {
    if (railway_gs[i] < 0) {
      dfs(railway_adj_lists, railway_gs, i, g++);
    }
  }

  // create vector of (road_g, railway_g)
  vector<pair<int, int>> pgs;
  for (int i = 0; i < N; i++) {
    pgs.push_back(pair<int, int>(road_gs[i], railway_gs[i]));
  }
  sort(pgs.begin(), pgs.end());

  // solve
  for (int i = 0; i < N; i++) {
    const pair<int, int> pg = pair<int, int>(road_gs[i], railway_gs[i]);
    const int cnt = upper_bound(pgs.begin(), pgs.end(), pg) -
                    lower_bound(pgs.begin(), pgs.end(), pg);
    printf("%d ", cnt);
  }
  printf("\n");
}