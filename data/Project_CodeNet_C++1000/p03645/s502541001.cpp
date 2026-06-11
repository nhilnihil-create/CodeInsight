#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, M; cin >> N >> M;
  
  set<int> memo;
  
  vector<pair<int, int>> vec(M);
  
  for (int i = 0; i < M; i++) {
    
    int a, b; cin >> a >> b;
    
    vec[i].first = a; vec[i].second = b;
    
  }
  
  sort(vec.begin(), vec.end());
  
  for (int i = 0; i < M; i++) {
    
    int tmpA = vec[i].first, tmpB = vec[i].second;
    
    if (tmpA == 1) memo.insert(tmpB);
    
    if (tmpB == N) {
      
      if (memo.count(tmpA)) { cout << "POSSIBLE" << endl; return 0; }
      
    }
    
  }
  
  cout << "IMPOSSIBLE" << endl;
  
}