#include <bits/stdc++.h>
using namespace std;
  
int main() {
  long long N,K;
  cin >> N >> K;
  vector<long long>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  
  if (N == 1){
    if (A.at(0) == K){
      cout << "POSSIBLE" << endl;
    }
    else {
      cout << "IMPOSSIBLE" << endl;
    }
    return 0;
  }
  
  int X = A.at(0);
  int Y = A.at(1);
  int Z = X % Y;
  int count;

  for (int i = 1; i < N; i++) {
    count = 0;
    while (count == 0){
      if (Z == 0){
        if (i != N-1){
          X = A.at(i+1);
          Z = X % Y;
        }
        count++;
      }
      else {
        X = Y;
        Y = Z;
        Z = X % Y;
      }
    }
  }
  
  if (K <= A.at(N-1) && K % Y == 0){
    cout << "POSSIBLE" << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}
    