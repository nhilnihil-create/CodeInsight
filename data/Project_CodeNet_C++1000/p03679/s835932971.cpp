#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (b-a <= 0) cout << "delicious" << endl;
  else {
    if (b-a >= x+1) cout << "dangerous" << endl; 
    if (b-a < x+1) cout << "safe" << endl;
  }
  
  return 0;
}