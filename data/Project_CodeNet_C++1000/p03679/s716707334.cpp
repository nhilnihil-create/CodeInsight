#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, A, B, day;
  cin >> X >> A >> B;
  day = A-B;
  
  if (day >= 0) cout << "delicious" << endl;
  else if (day + X >= 0) cout << "safe" << endl;
  else cout << "dangerous" << endl;
}