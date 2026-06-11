#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string A, B, C;
  cin >> A >> B >> C;

  int a = A.size() - 1;
  int b = B.size() - 1;
  
  if (A.at(a) == B.at(0) && B.at(b) == C.at(0)) {
    cout << "YES" <<endl;
  }
  else {
    cout << "NO" <<endl;
  }
  
return 0;
}