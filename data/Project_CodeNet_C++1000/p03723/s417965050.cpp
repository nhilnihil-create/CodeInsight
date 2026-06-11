#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >>a >>b >>c;
  
  if (a==b && b==c) {
    if (a % 2 == 0)
      cout << -1 << endl;
    else
      cout << 0 << endl;
  }
  else {
    int count = 0;
    while (1) {
      if (a%2==1 || b%2==1 || c%2==1)
        break;
      int a2 = a, b2 = b, c2 = c;
      count ++;      

      a = (b2 + c2) / 2;
      b = (a2 + c2) / 2;
      c = (a2 + b2) / 2;
    }
    cout << count << endl;  
  }
}