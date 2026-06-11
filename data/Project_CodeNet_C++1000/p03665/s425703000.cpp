#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,P;
  cin >> N >> P;
  vector<int>A(N);
  int count = 0;
  long long sum = 1;
  
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum *= 2;
    if (A.at(i) % 2 == 1){
      count = 1;
    }
  }
  
  if (count == 1){
    cout << sum/2 << endl;
  }
  else {
    if (P == 0){
      cout << sum << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
}
  
  