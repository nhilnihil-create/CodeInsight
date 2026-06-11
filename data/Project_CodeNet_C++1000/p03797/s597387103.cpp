#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m;
  cin >> n >> m;
  if(m/2<=n) cout <<m/2;
  else cout << (m+2*n)/4;
  return 0;
}