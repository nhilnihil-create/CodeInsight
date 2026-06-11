#include <bits/stdc++.h>

using namespace std;

int main() {
  long long i, o, j, l, _;
  cin >> i >> o >> _ >> j >> l >> _ >> _;
  
  long long res = o + i/2*2 + j/2*2 + l/2*2;
  if (i && j && l)
    res = max(res, o + (i-1)/2*2 + (j-1)/2*2 + (l-1)/2*2 + 3);
  cout << res << endl;
  return 0;
}
