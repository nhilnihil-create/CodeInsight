#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
int main(){
  int N;
  cin >> N;
  vector<vector<pair<long long, int>>> E(N);
  for (int i = 0; i < N - 1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a].push_back(make_pair(c, b));
    E[b].push_back(make_pair(c, a));
  }
  int Q, K;
  cin >> Q >> K;
  K--;
  vector<long long> d(N, INF);
  d[K] = 0;
  queue<int> q;
  q.push(K);
  while (!q.empty()){
    int v = q.front();
    q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (d[w] == INF){
        d[w] = d[v] + P.first;
        q.push(w);
      }
    }
  }
  for (int i = 0; i < Q; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << d[x] + d[y] << endl;
  }
}