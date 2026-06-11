#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> table(N, vector<int>(M));
  for (int i =0; i < N; i++) for (int j = 0; j < M; j++) cin >> table[i][j];
  
  for (int i = 0; i < N; i++) {
    vector<int> buffer(M);
    for (int j = 0;j < M;j++) {
      buffer[table[i][j]-1] = j+1;
    }
    for (int j = 0; j < M;j++) table[i][j] = buffer[j];
  }
  
  int ans = N;
  vector<bool> avail(M, true);
  for (int q = 0; q < M; q++) {
    vector<int> sums(M, 0);
    for (int i =0; i < N; i++) {
      int ma = M+1;
      int ma_idx = -1;
      for (int j = 0; j < M; j++) {
        if (!avail[j]) continue;
        if (table[i][j] < ma) {
          ma = table[i][j];
          ma_idx = j;
        }
      }
      
      sums[ma_idx]++;
    }
    
    int mx = -1;
    int mx_idx = -1;
    for (int j = 0; j < M; j++) {
      if (sums[j] > mx) {
        mx = sums[j];
        mx_idx = j;
      }
    }
    avail[mx_idx] = false;
    ans = min(ans, mx);
  }
  
  cout << ans << endl;
}