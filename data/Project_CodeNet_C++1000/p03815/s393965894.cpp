#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t x, a, b;
  cin >> x;
  a=x/11;
  b=x%11;
  if(b==0)
    cout << 2*a;
  else if(b<7)
    cout << 1+2*a;
  else
    cout << 2+2*a;
  return 0;
}