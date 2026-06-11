#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<long long> S(N);
  S[0] = A[0];
  for (int i = 1; i < N; i++){
    S[i] = S[i - 1] + A[i];
  }
  int m = 0;
  for (int i = 1; i < N; i++){
    if (A[i] > S[i - 1] * 2){
      m = i;
    }
  }
  cout << N - m << endl;
}