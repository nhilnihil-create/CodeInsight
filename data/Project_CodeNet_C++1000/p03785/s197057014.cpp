#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);
  sort(T.begin(), T.end());
  
  int ans = 0;
  int i = 0;
  
  while(i < N){
    ans++;
    int next = C;
    for (int j = 0; j < C; j++){
      if (i + j == N){
        next = j;
        break;
      }
      else if (T.at(i + j) > T.at(i) + K){
        next = j;
        break;
      }
    }
    i += next;
  }
  
  cout << ans << endl;
}