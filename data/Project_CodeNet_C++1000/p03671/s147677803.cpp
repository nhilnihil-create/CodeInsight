#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int k = max(a, b);
  int ans = a + b + c;
  k = max(k, c);
  
  cout << ans - k << endl;
}