#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  }
  long long S = 0;
  for (int i = N - 1; i >= 0; i--){
    int r = (A[i] + S) % B[i];
    if (r != 0){
      S += B[i] - r;
    }
  }
  cout << S << endl;
}