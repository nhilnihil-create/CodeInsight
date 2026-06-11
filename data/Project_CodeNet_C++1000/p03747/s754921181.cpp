#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  long long L, T;
  cin >> N >> L >> T;
  vector<long long> X(N), W(N);
  for (int i = 0; i < N; i++){
    cin >> X[i] >> W[i];
  }
  vector<long long> X2(N);
  for (int i = 0; i < N; i++){
    if (W[i] == 1){
      X2[i] = (X[i] + T) % L;
    } else {
      X2[i] = (X[i] - T % L + L) % L;
    }
  }
  sort(X2.begin(), X2.end());
  long long sum1 = 0;
  for (int i = 0; i < N; i++){
    sum1 += X[i];
  }
  for (int i = 0; i < N; i++){
    if (W[i] == 1){
      sum1 += T;
    } else {
      sum1 -= T;
    }
  }
  long long sum2 = 0;
  for (int i = 0; i < N; i++){
    sum2 += X2[i];
  }
  int C = (sum2 - sum1) / L;
  for (int i = 0; i < N; i++){
    cout << X2[(i - C % N + N) % N] << endl;
  }
}