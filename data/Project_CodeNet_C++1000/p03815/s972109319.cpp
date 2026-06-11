#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  cin >> x;
  if (!(x%11)) {
    cout << x/11*2;
  } else if (x%11 <= 6) {
    cout << x/11*2+1;
  } else {
    cout << x/11*2+2;
  }
}