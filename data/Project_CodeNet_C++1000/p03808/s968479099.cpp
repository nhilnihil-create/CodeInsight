#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  long long sum = 0;
  for (int i = 0; i < N; i++){
    sum += A[i];
  }
  long long C = N * (N + 1) / 2;
  if (sum % C != 0){
    cout << "NO" << endl;
  } else {
    long long cnt = sum / C;
    vector<long long> D(N);
    for (int i = 0; i < N - 1; i++){
      D[i] = A[i + 1] - A[i];
    }
    D[N - 1] = A[0] - A[N - 1];
    for (int i = 0; i < N; i++){
      D[i] -= cnt;
    }
    bool ok = true;
    /*
    for (int i = 0; i < N; i++){
      cout << D[i] << ' ';
    }
    cout << endl;
    */
    for (int i  = 0; i < N - 1; i++){
      if (D[i] % N != 0 || D[i] > 0){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}