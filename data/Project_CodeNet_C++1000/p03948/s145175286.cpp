#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<int> Cmax(N);
  Cmax[N - 1] = A[N - 1];
  for (int i = N - 2; i >= 0; i--){
    Cmax[i] = max(Cmax[i + 1], A[i]);
  }
  int M = 0;
  /*
  for (int i = 0; i < N; i++){
    cout << Cmax[i] <<  ' ';
  }
  cout << endl;
  */
  for (int i = 0; i < N; i++){
    M = max(M, Cmax[i] - A[i]);
  }
  //cout << M << endl;
  int count = 0;
  for (int i = 0; i < N; i++){
    if (Cmax[i] - A[i] == M){
      count++;
    }
  }
  cout << count << endl;
}