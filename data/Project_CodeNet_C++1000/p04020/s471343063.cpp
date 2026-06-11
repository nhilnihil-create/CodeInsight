#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<long long> dp0(N, 0);
  vector<long long> dp1(N, 0);
  if (A[0] % 2 == 0){
    dp0[0] = A[0] / 2;
    if (A[0] == 0){
      dp1[0] = -INF;
    } else {
      dp1[0] = A[0] / 2 - 1;
    }
  } else {
    dp0[0] = A[0] / 2;
    dp1[0] = A[0] / 2;
  }
  for (int i = 1; i < N; i++){
    if (A[i] % 2 == 0){
      if (A[i] == 0){
        dp0[i] = dp0[i - 1];
        dp1[i] = -INF;
      } else {
        dp0[i] = max(dp0[i - 1] + A[i] / 2, dp1[i - 1] + 1 + (A[i] - 1) / 2);
        dp1[i] = max(dp0[i - 1] + (A[i] - 1) / 2, dp1[i - 1] + (A[i] - 2) / 2 + 1);
      }
    } else {
      dp0[i] = max(dp0[i - 1] + A[i] / 2, dp1[i - 1] + A[i] / 2 + 1);
      if (A[i] == 1){
        dp1[i] = dp0[i - 1] + A[i] / 2;
      } else {
        dp1[i] = max(dp0[i - 1] + A[i] / 2, dp1[i - 1] + (A[i] - 2) / 2 + 1);
      }
    }
  }
  cout << dp0[N - 1] << endl;
}