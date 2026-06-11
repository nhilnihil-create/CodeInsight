#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  ll int n,a, b;
  cin >> n >> a >> b;
  if(a > b || (n == 1 && a != b)) {
    cout << 0 << endl;
    return 0;
  } else if(a == b && n == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  ll int ans = (b - a) * (n - 2) + 1;
  
  
  cout << ans << endl;

  return 0;
}
