#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, c;
  char b;
  cin >> a >> b >> c;
  
  if (b == '+') {
    cout << a + c << endl;
  }
  else {
    cout << a - c << endl;
  }
}