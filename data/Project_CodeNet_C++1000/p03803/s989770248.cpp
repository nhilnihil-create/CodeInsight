#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  if (A < B) {
    if (A == 1) {
      cout << "Alice" << endl;
      return 0;
    }  
    cout << "Bob" << endl; 
  } else if (A > B) {
    if (B == 1) {
      cout << "Bob" << endl;
      return 0;
    }
    cout << "Alice" << endl;
  } 
  else if (A == B) cout << "Draw" << endl;  
}