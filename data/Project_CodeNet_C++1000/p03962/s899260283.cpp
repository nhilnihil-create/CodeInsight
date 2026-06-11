#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  int ans = 0;
  cin >> a;
  ans = 1;
  
  cin >> b;
  if(a != b) {
    ans++;
    cin >> c;
    if(a != c && b != c) ans++;
  } else {
    cin >> c;
    if (a != c) ans++;
  }
  cout << ans << endl;
}