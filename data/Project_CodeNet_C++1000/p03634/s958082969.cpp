#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<queue<int>>tree(N + 1);
  vector<queue<int>>length(N + 1);
  vector<long long>Le(N - 1);
  for (int i = 0; i < N - 1; i ++) {
    int a, b;
    cin >> a >> b >> Le[i];
    tree[a].push(b);
    tree[b].push(a);
    length[a].push(i);
    length[b].push(i);
  }
  int Q, K;
  cin >> Q >> K;
  queue<int>que;
  vector<long long>ans(N + 1, -1);
  ans[K] = 0;
  que.push(K);
  while(!que.empty()) {
    int u = que.front();
    while(!tree[u].empty()) {
      int ne = tree[u].front();
      long long ln = Le[length[u].front()];
      tree[u].pop();
      length[u].pop();
      if (ans[ne] != -1) continue;
      que.push(ne);
      ans[ne] = ans[u] + ln;
    }
    que.pop();
  }
  for (int i = 0; i < Q; i ++) {
    int a, b;
    cin >> a >> b;
    cout << ans[a] + ans[b] << endl;
  }
}
