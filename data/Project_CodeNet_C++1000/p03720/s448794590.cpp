#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M, a, b;
  cin >> N >> M;
  
  vector<int> road(N, 0); // 各都市から伸びる道路本数を格納する配列
  
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    road[a - 1]++; // 都市名と配列での順番の差を埋めるため -1
    road[b - 1]++;
  }

  for (int i = 0; i < N; i++) {
    cout << road[i] << endl;
  }
}