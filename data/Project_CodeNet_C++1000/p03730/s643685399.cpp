#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >>B >>C;
  
  bool ans = false;
  for ( int i = 0 ; i < 10000; i++ ){
    if ( A * i % B == C ){
      ans = true;
      break;
    }
  }
  
  if (ans) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
}
    
  
  