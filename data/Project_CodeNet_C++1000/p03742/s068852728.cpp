#include <bits/stdc++.h>
using namespace std;

void prians(bool answer) {
  if(answer)
    cout << "Brown" << endl;
  else
    cout << "Alice" << endl;
}
long long x, y, cnt = 0;

int main() {
  cin >> x >> y;
  prians(x == y || (max(x, y) - min(x, y) == 1));
  return 0;
}