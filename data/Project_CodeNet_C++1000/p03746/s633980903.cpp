#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

deque<int> dq;
vector<int> G[100010];
bool used[100010];
int n, m;

void dfs(int k, bool f) {
  used[k] = 1;
  for (int i = 0; i < G[k].size(); i++) {
    if (!used[G[k][i]]) {
      if (f) dq.push_back(G[k][i]);
      else dq.push_front(G[k][i]);
      dfs(G[k][i], f);
      return;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dq.push_back(1);
  dfs(1, 1);
  dfs(1, 0);
  cout << dq.size() << endl;
  while (1) {
    cout << dq.front();
    dq.pop_front();
    if (!dq.empty()) cout << " ";
    else {
      cout << endl;
      break;
    }
  }
  return 0;
}
