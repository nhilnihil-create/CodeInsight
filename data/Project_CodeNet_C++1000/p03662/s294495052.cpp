#include <bits/stdc++.h>

using namespace std;

const int N_ = int(1.1e5);

int N;
vector<int> gph[N_];

int ans;

int par[N_];

void dfs(int u, int p = -1) {
  par[u] = p;
  for(int v : gph[u]) if(v != p) dfs(v, u);
}

int stop;
int cnt;
  vector<int> pth;
void dfs2(int u, int p = -1) {
  if(u == stop) return;
  cnt += 1;
  for(int v : gph[u]) {
    if(v != p) {
      dfs2(v, u);
    }
  }
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N-1; i++) {
    int u, v; scanf("%d%d", &u, &v);
    gph[u].push_back(v);
    gph[v].push_back(u);
  }

  dfs(1);

  for(int i = N; i > 0; i = par[i]) {
    pth.push_back(i);
  }
  reverse(pth.begin(), pth.end());

  stop = pth[(int)(pth.size() + 1) / 2];

  dfs2(1);

  puts(cnt > N - cnt ? "Fennec" : "Snuke");
  return 0;
}