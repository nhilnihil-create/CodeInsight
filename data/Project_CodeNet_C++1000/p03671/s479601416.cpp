#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 500000;
  if(a + b < ans) ans = a + b;
  if(a + c < ans) ans = a + c;
  if(b + c < ans) ans = b + c;
  cout << ans;
 return 0;
}

