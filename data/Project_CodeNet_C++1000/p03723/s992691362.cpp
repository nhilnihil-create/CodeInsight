#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c;
  if(a == b && b == c) {
    if(a % 2 == 0) {
      cout << -1 << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  else {
    int count = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
      int ca = a, cb = b, cc = c;
      a = cb/2 + cc/2;
      b = ca/2 + cc/2;
      c = ca/2 + cb/2;
      count++;
    }
    cout << count << endl;
  }
}