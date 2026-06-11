#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int x, y;
  cin >> x >> y ;

  set<int> B;
  B.insert(4);
  B.insert(6);
  B.insert(9);
  B.insert(11);
  
  if (x == 2 || y == 2) {
    cout << "No" << endl;
  }
  else if (B.count(x) > 0 && B.count(y) > 0) {
    cout << "Yes" << endl;
  }
  else if (B.count(x) == 0 && B.count(y) == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
  
return 0;
}