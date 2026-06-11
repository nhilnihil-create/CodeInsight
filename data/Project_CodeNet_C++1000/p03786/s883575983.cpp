#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  long long sum = 0;
  vector<long long>A(N);
  vector<long long>B(N);
     
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  
  for (int i = 0; i < N; i++) {
    B.at(i) = sum;
    sum += A.at(i);
  }
  
  vector<int>C(N,0);
  for (int i = 0; i < N; i++) {
    if (A.at(i) <= B.at(i)*2){
      C.at(i)++;
    }
  }
  
  int ans = 1;
  reverse(C.begin(), C.end());
  for (int i = 0; i < N; i++) {
    if (C.at(i) > 0){
      ans++;
    }
    else {
      break;
    }
  }
  
  cout << ans << endl;
}
  
  