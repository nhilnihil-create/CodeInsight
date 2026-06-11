#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a;
  char x;
  cin >> x;
  cin >> b;
  if (x == '+') {
    cout << a+b << endl;
  }
  else {
    cout << a-b << endl;
  }
}