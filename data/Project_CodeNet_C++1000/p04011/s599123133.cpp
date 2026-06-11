#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  int ans = 0;
  if(n <= k) ans = n * x;
  else ans = k*x + (n-k)*y;
  cout << ans << endl;
}