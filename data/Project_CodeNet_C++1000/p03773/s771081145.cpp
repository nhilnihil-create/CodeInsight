#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A=0, B=0;
  
  cin >> A >> B;
  
  int times = A+B;
  
  if(B==0) {
    
    cout << A << endl;
    
  } else if(24<=times) {
    
    cout << times-24 << endl;
    
  } else {
    
    cout << times << endl;
    
  }
  
  return 0;
  
}