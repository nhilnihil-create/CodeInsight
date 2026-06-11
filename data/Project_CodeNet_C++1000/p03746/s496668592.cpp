#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  vector<bool> used(N, false);
  vector<int> path1;
  path1.push_back(0);
  vector<int> path2;
  path2.push_back(E[0][0]);
  used[0] = true;
  used[E[0][0]] = true;
  while (1){
    int v = path1.back();
    int next = -1;
    for (int w : E[v]){
      if (!used[w]){
        next = w;
      }
    }
    if (next == -1){
      break;
    }
    used[next] = true;
    path1.push_back(next);
  }
  while (1){
    int v = path2.back();
    int next = -1;
    for (int w : E[v]){
      if (!used[w]){
        next = w;
      }
    }
    if (next == -1){
      break;
    }
    used[next] = true;
    path2.push_back(next);
  }
  reverse(path1.begin(), path1 .end());
  vector<int> path;
  for (int v : path1){
    path.push_back(v);
  }
  for (int v : path2){
    path.push_back(v);
  }
  int sz = path.size();
  cout << sz << endl;
  for (int i = 0; i < sz; i++){
    cout << path[i] + 1;
    if (i < sz - 1){
      cout << ' ';
    }
  }
  cout << endl;
}