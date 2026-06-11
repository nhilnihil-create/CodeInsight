#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a;
  
  for(int i = 7;i >= 0;i--) {
    b = pow(2, i);
    if(b <= a) {
      cout << b << endl;
      break;
    }
  }
}
