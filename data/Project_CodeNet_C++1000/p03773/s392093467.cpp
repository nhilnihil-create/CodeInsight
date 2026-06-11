#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = a+b;
  if(ans > 23) ans -= 24;
  cout << ans << endl;
  return 0;
}
