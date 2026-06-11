#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A=0, B=0, C=0;
  
  cin >> A >> B >> C;
  
  int sub1= B-A;
  int sub2= C-B;
  
  if(sub1==sub2) {
    
    cout << "YES" << endl;
    
  } else if(sub1!=sub2) {
    
    cout << "NO" << endl;
    
  }
  
  return 0;
  
}