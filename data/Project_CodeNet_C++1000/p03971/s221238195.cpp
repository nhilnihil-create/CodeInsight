#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a, b;
  string s;
  cin >>n >>a >>b >>s;
  
  int pass = 0, bcount = 0;
  for (int i = 0; i < n; i++) {
    
    if (s[i]=='a') {
      if (pass < a+b) {
        cout << "Yes" << endl;
        pass ++;
      }
      else
        cout << "No" << endl;
    }
    
    else if (s[i]=='b') {
      bcount ++;
      if (pass < a+b && bcount <= b) {
        cout << "Yes" << endl;
        pass ++;
      }
      else
        cout << "No" << endl;
    }
    
    else
      cout << "No" << endl;
    
  }

}