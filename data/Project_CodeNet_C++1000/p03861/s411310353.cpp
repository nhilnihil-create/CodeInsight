#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int64_t a, b, x, ans;
  cin >> a >> b >> x;
  if (a%x==0 && b%x==0) {
    ans=(b-a+x)/x;
  }
  else {
    if (a%x==0) {
      ans=(b-(b%x)-a+x)/x;
    }
    else {
      if (b%x==0) {
        ans=(b-a+(a%x))/x;
      }
      else {
        ans=(b-(b%x)-a+(a%x))/x;
      }
    }
  }
  cout << ans << endl;
}
