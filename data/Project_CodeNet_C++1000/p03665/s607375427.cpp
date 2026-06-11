#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, P;
  cin >> N >> P;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int O = 0, E = 0;
  for (int i = 0; i < N; i++){
    if (A[i] % 2 == 0){
      E++;
    } else {
      O++;
    }
  }
  if (P == 0){
    if (O == 0){
      cout << ((long long) 1 << E) << endl;
    } else {
      cout << ((long long) 1 << (O + E - 1)) << endl;
    }
  } else {
    if (O == 0){
      cout << 0 << endl;
    } else {
      cout << ((long long) 1 << (O + E - 1)) << endl;
    }
  }
}