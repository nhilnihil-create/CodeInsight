#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define MAX_N (100000)
#define MAX_M (100000)

using namespace std;

void find_path(const vector<vector<int>> &adj_lists, vector<int> &path,
               vector<int> &us, int cur) {
  // printf("%d\n", cur);
  for (const int nxt : adj_lists[cur]) {
    if (!us[nxt]) {
      us[nxt] = 1;
      path.push_back(nxt);
      find_path(adj_lists, path, us, nxt);
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  // read inputs
  int N, M, as[MAX_M], bs[MAX_M];
  scanf("%d %d", &N, &M);
  for (int k = 0; k < M; k++) {
    scanf("%d %d", &as[k], &bs[k]);
    as[k]--;  // NOTE : modified input
    bs[k]--;  // NOTE : modified input
  }

  // create graph
  vector<vector<int>> adj_lists(N, vector<int>());
  for (int k = 0; k < M; k++) {
    const int a = as[k], b = bs[k];
    adj_lists[a].push_back(b);
    adj_lists[b].push_back(a);
  }

  // solve
  vector<int> path1, path2, us(N, 0);
  us[0] = 1;
  find_path(adj_lists, path1, us, 0);
  find_path(adj_lists, path2, us, 0);

  // print answer
  printf("%d\n", (int) path1.size() + (int) path2.size() + 1);
  for (int i = path1.size() - 1; i >= 0; i--) {
    printf("%d\n", path1[i] + 1);
  }
  printf("%d\n", 0 + 1);
  for (int i = 0; i < path2.size(); i++) {
    printf("%d\n", path2[i] + 1);
  }

  return 0;
}
