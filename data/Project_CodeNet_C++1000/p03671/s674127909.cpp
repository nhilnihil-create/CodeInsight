#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int ab = a + b;
  int bc = b + c;
  int ac = a + c;
  
  cout << min( ab, min (bc, ac) ) << endl;
}