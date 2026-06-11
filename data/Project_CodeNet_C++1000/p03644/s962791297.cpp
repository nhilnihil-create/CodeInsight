#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x;
  cin >> a;
  
  for(int i = 0;i < 7;i++) {
    b = pow(2, i);
    if(b <= a) {
      x = b;
    }
  }
  cout << x << endl;
}