#include <bits/stdc++.h>
using namespace std;
 
int main() {
int A,B;
  cin >> A >> B;
  
  if(A < 0 && B > 0){
  cout << "Zero" << endl;
  }
  
  if(A < 0 && B < 0 && (B - A) % 2 == 0){
    cout << "Negative" << endl;
  }
  
  if(A < 0 && B < 0 && (B - A) % 2 != 0){
    cout << "Positive" << endl;
  }
  
  if(A > 0 && B > 0){
    cout << "Positive" << endl;
  }  
}
