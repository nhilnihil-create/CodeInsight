#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  
  int ans = a - b;
  if(ans >= 0) cout << "delicious" << endl;
  else if(abs(ans) <= x) cout << "safe" << endl;
  else cout << "dangerous" << endl;
}