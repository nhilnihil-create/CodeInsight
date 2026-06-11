#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; i++){
    cin >> T[i];
  }
  sort(T.begin(), T.end());
  vector<long long> T2(N * 2);
  for (int i = 0; i < N; i++){
    T2[i * 2] = T[i];
    T2[i * 2 + 1] = T[i] + K;
  }
  sort(T2.begin(), T2.end());
  int ans = 0;
  int cnt = 0;
  queue<int> Q;
  for (int i = 0; i < N * 2; i++){
    if (cnt < N){
      while (T[cnt] == T2[i]){
        Q.push(T[cnt]);
        cnt++;
        if (cnt < N){
          break;
        }
      }
    }
    if (!Q.empty()){
      if (Q.front() + K == T2[i]){
        while (Q.front() + K == T2[i]){
          vector<int> bus;
          while (!Q.empty()){
            bus.push_back(Q.front());
            Q.pop();
            if (bus.size() == C){
              break;
            }
          }
          ans++;
          if (Q.empty()){
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;
}