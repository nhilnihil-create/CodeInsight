#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n, k, x, y; cin >> n >> k >> x >> y;
  cout << min(k, n) * x + (n - min(k, n)) * y << endl;

  return 0;
}