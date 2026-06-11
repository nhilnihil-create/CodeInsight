#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int64_t X, ans;
  cin >> X;
  ans=1;
  for (int64_t i=1; i<X; i++) {
    if (i*(i+1)<2*X) {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}
