#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  
  if (N == 1){
    cout << 1 << endl;
    return 0;
  }
  
  vector<int>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  int count = 1;
  int sum = 0;
  for (int i = 0; i < N-1; i++) {
    if (A.at(i) == A.at(i+1)){
      count++;
      if (i == N-2){
        if (count % 2 == 1){
          sum++;
        }
      }
    }
    else {
      if (count % 2 == 1){
        sum++;
      }
      if (i == N-2){
        sum++;
      }
      count = 1;
    }
  }
  cout << sum << endl;
}
      
      